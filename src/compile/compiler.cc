#include <compile/compiler.hh>
#include <ast/all.hh>
#include <bytecode/all.hh>

namespace compile
{
    Compiler::Compiler()
        : ast::DefaultConstVisitor()
        , local_(false)
        , var_scope_(misc::ScopedMap<misc::symbol, int>(INT_MIN))
        , fun_scope_(misc::ScopedMap<misc::symbol, int>(INT_MIN))
        , var_addr_(0)
        , fun_addr_(0)
        , ro_data_counter_(0)
        , error_(false)
        , assign_(false)
    {}

    Compiler::~Compiler()
    {}

    void Compiler::operator()(const ast::AstList& list)
    {
        for (auto node : list.list_get())
        {
            node->accept(*this);

            // Some node needs a pop to clean the stack
            // (assignation, calculus, ...)
            if (!dynamic_cast<ast::IfInstr*> (node)
                && !dynamic_cast<ast::FunctionDec*> (node))
                exec_.add_instruction(new bytecode::Pop(node->location_get()));
        }
    }

    void Compiler::operator()(const ast::IntExp& exp)
    {
        exec_.add_instruction(new bytecode::LoadInt(exp.location_get(),
                                                    exp.value_get()));
    }

    void Compiler::operator()(const ast::StringExp& exp)
    {
        exec_.add_instruction(new bytecode::LoadStr(exp.location_get(),
                                                    ro_data_get(exp.value_get())));
    }

    void Compiler::operator()(const ast::OpExp& exp)
    {
        exp.lop_get()->accept(*this);
        exp.rop_get()->accept(*this);

        exec_.add_instruction(new bytecode::Operation(exp.location_get(),
                                                      exp.op_get()));
    }

    void Compiler::operator()(const ast::FunctionCallExp& exp)
    {
        // Fetching function address
        int fun_addr = fun_scope_.get(exp.name_get());

        // Delimit function call formals
        exec_.add_instruction(new bytecode::Delim(exp.location_get()));

        // Formal needs to be process in reverse order
        typedef std::list<ast::Exp*>::const_reverse_iterator ExpIterator;
        ExpIterator it = exp.args_get()->list_get().rbegin();
        ExpIterator end = exp.args_get()->list_get().rend();

        for ( ; it != end; ++it)
        {
            (*it)->accept(*this);
        }

        // Add the call instruction
        exec_.add_instruction(new bytecode::CallFunction(exp.location_get(),
                                                         fun_addr));
    }

    void Compiler::operator()(const ast::ReturnExp& exp)
    {
        if (exp.exp_get())
            exp.exp_get()->accept(*this);

        exec_.add_instruction(new bytecode::Return(exp.location_get()));
    }

    void Compiler::operator()(const ast::BreakExp&)
    {
    }

    void Compiler::operator()(const ast::ContinueExp&)
    {
    }

    void Compiler::operator()(const ast::NewExp& exp)
    {
    }

    void Compiler::operator()(const ast::AssignExp& exp)
    {
        exp.exp_get()->accept(*this);

        assign_ = true;
        exp.var_get()->accept(*this);
        assign_ = false;
    }

    void Compiler::operator()(const ast::IfInstr& instr)
    {
        instr.condition_get()->accept(*this);

        bytecode::JumpFalse* jmp = new bytecode::JumpFalse(instr.location_get(),
                                                           0);

        exec_.add_instruction(jmp);

        int offset = exec_.code_get().size();

        instr.exp_true_get()->accept(*this);

        offset = exec_.code_get().size() - offset + 1;

        jmp->offset_set(offset);

        if (instr.exp_else_get())
            instr.exp_else_get()->accept(*this);
    }

    void Compiler::operator()(const ast::ElseInstr& instr)
    {
    }

    void Compiler::operator()(const ast::WhileInstr& instr)
    {
    }

    void Compiler::operator()(const ast::InstrList& list)
    {
        for (auto instr : list.list_get())
        {
            instr->accept(*this);
            exec_.add_instruction(new bytecode::Pop(instr->location_get()));
        }
    }

    void Compiler::operator()(const ast::ImportInstr& instr)
    {
        exec_.add_instruction(new bytecode::OpenModule(instr.location_get(),
                                                       instr.name_get()));
    }

    void Compiler::operator()(const ast::VarId& var)
    {
        if (assign_)
        {
            if (local_)
            {
                int addr_var = addr_get(var.name_get(), var_scope_,
                                        var_addr_);
                exec_.add_instruction(new bytecode::StoreLocal(var.location_get(),
                                                               addr_var));
            }
            else
                exec_.add_instruction(new bytecode::StoreVar(var.location_get(),
                                                             ro_data_get(var.name_get())));
        }
        else
        {
            if (local_)
            {
                int addr_var = addr_get(var.name_get(), var_scope_,
                                        var_addr_);
                exec_.add_instruction(new bytecode::LoadLocal(var.location_get(),
                                                              addr_var));
            }
            else
                exec_.add_instruction(new bytecode::LoadVar(var.location_get(),
                                                            ro_data_get(var.name_get())));
        }
    }

    void Compiler::operator()(const ast::AttributVar& var)
    {
    }

    void Compiler::operator()(const ast::MethodCallVar& var)
    {
    }

    void Compiler::operator()(const ast::ModuleCallVar& var)
    {
    }

    void Compiler::operator()(const ast::ModuleAttributVar& var)
    {
    }

    void Compiler::operator()(const ast::ArrayVar& var)
    {
    }

    void Compiler::operator()(const ast::FunctionDec& dec)
    {
        local_ = true;
        var_addr_ = 0;

        var_scope_.scope_begin();

        int addr_fun = addr_get(dec.name_get(), fun_scope_,
                                fun_addr_);

        exec_.add_instruction(new bytecode::RegisterFunction(dec.location_get(),
                                                             addr_fun));

        // Prepare jump instruction
        // offset is 0 because not known yet
        bytecode::Jump* jump = new bytecode::Jump(dec.location_get(), 0);

        exec_.add_instruction(jump);

        int offset = exec_.code_get().size();

        dec.args_get()->accept(*this);
        dec.body_get()->accept(*this);

        offset = exec_.code_get().size() - offset + 2;

        exec_.add_instruction(new bytecode::Return(dec.location_get()));

        jump->offset_set(offset);

        var_scope_.scope_end();

        local_ = false;
    }

    void Compiler::operator()(const ast::VarDec& dec)
    {
        // Only function, method parameter
        // So put put adress on map and generate bytecode instr

        int addr = var_addr_;

        var_scope_.add(dec.name_get(), addr);

        exec_.add_instruction(new bytecode::StoreLocal(dec.location_get(),
                                                       addr));

        // Increment local adress
        ++var_addr_;
    }

    void Compiler::operator()(const ast::MethodDec& dec)
    {
    }

    void Compiler::operator()(const ast::AttributDec& dec)
    {
    }

    void Compiler::operator()(const ast::ClassDec& dec)
    {
    }

    void Compiler::operator()(const ast::DecList& list)
    {
    }

    int Compiler::ro_data_get(const std::string& str)
    {
        std::map<std::string, int>::iterator it;

        it = ro_data_.find(str);

        if (it != ro_data_.end())
            return it->second;
        else
        {
            ro_data_.insert(std::pair<std::string, int>(str, ro_data_counter_));
            exec_.add_ro_data(str);

            return ro_data_counter_++;
        }
    }

    int Compiler::addr_get(const std::string& str,
                           misc::ScopedMap<misc::symbol, int>& scope,
                           int& scope_addr)
    {
        int addr = scope.get(str);

        if (addr == INT_MIN)
        {
            addr = scope_addr++;
            scope.add(str, addr);
        }

        return addr;
    }
} // namespace compile
