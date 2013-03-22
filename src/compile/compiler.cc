#include <compile/compiler.hh>
#include <ast/all.hh>
#include <bytecode/all.hh>

namespace compile
{
    Compiler::Compiler()
        : Visitor()
        , local_(false)
        , var_scope_(misc::ScopedMap<misc::symbol, int>(INT_MIN))
        , ro_data_counter_(0)
        , error_(false)
    {}

    Compiler::~Compiler()
    {}

    void Compiler::operator()(ast::AstList& list)
    {
        for (auto node : list.list_get())
        {
            node->accept(*this);
            exec_.add_instruction(new bytecode::Pop(node->location_get()));
        }
    }

    void Compiler::operator()(ast::IntExp& exp)
    {
        exec_.add_instruction(new bytecode::LoadInt(exp.location_get(),
                                                    exp.value_get()));
    }

    void Compiler::operator()(ast::StringExp& exp)
    {
        exec_.add_instruction(new bytecode::LoadStr(exp.location_get(),
                                                    ro_data_get(exp.value_get())));
    }

    void Compiler::operator()(ast::OpExp& exp)
    {
        exp.lop_get()->accept(*this);
        exp.rop_get()->accept(*this);

        exec_.add_instruction(new bytecode::Operation(exp.location_get(),
                                                      exp.op_get()));
    }

    void Compiler::operator()(ast::FunctionCallExp& exp)
    {
    }

    void Compiler::operator()(ast::ReturnExp& exp)
    {
        if (exp.exp_get())
            exp.exp_get()->accept(*this);

        exec_.add_instruction(new bytecode::Return(exp.location_get()));
    }

    void Compiler::operator()(ast::BreakExp&)
    {
    }

    void Compiler::operator()(ast::ContinueExp&)
    {
    }

    void Compiler::operator()(ast::NewExp& exp)
    {
    }

    void Compiler::operator()(ast::AssignExp& exp)
    {
    }

    void Compiler::operator()(ast::IfInstr& instr)
    {
    }

    void Compiler::operator()(ast::ElseInstr& instr)
    {
    }

    void Compiler::operator()(ast::WhileInstr& instr)
    {
    }

    void Compiler::operator()(ast::InstrList& list)
    {
    }

    void Compiler::operator()(ast::ImportInstr& instr)
    {
        exec_.add_instruction(new bytecode::OpenModule(instr.location_get(),
                                                       instr.name_get()));
    }

    void Compiler::operator()(ast::VarId& var)
    {
    }

    void Compiler::operator()(ast::AttributVar& var)
    {
    }

    void Compiler::operator()(ast::MethodCallVar& var)
    {
    }

    void Compiler::operator()(ast::ModuleCallVar& var)
    {
    }

    void Compiler::operator()(ast::ModuleAttributVar& var)
    {
    }

    void Compiler::operator()(ast::ArrayVar& var)
    {
    }

    void Compiler::operator()(ast::FunctionDec& dec)
    {
        local_ = true;
        local_addr_ = 0;

        dec.args_get()->accept(*this);
        dec.body_get()->accept(*this);

        local_ = false;
    }

    void Compiler::operator()(ast::VarDec& dec)
    {
        // Only function, method parameter
        // So put put adress on map and generate bytecode instr

        int addr = local_addr_;

        var_scope_.add(dec.name_get(), addr);

        exec_.add_instruction(new bytecode::StoreLocal(dec.location_get(),
                                                       addr));

        // Increment local adress
        ++local_addr_;
    }

    void Compiler::operator()(ast::MethodDec& dec)
    {
    }

    void Compiler::operator()(ast::AttributDec& dec)
    {
    }

    void Compiler::operator()(ast::ClassDec& dec)
    {
    }

    void Compiler::operator()(ast::DecList& list)
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
} // namespace compile
