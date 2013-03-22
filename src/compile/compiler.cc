#include <compile/compiler.hh>
#include <ast/all.hh>
#include <bytecode/all.hh>

namespace compile
{
    Compiler::Compiler()
        : Visitor()
        , local_(false)
        , var_scope_(misc::ScopedMap<misc::symbol, int>(INT_MIN))
        , error_(false)
    {}

    Compiler::~Compiler()
    {
       for (auto elem : bytecode_)
           delete elem;
    }

    void Compiler::operator()(ast::AstList& list)
    {
    }

    void Compiler::operator()(ast::IntExp& exp)
    {
    }

    void Compiler::operator()(ast::StringExp& exp)
    {
    }

    void Compiler::operator()(ast::OpExp& exp)
    {
    }

    void Compiler::operator()(ast::FunctionCallExp& exp)
    {
    }

    void Compiler::operator()(ast::ReturnExp& exp)
    {
        if (exp.exp_get())
            exp.exp_get()->accept(*this);

        bytecode_.push_back(new bytecode::Return(exp.location_get()));
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
        bytecode_.push_back(new bytecode::OpenModule(instr.location_get(),
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

        local_ = false;
    }

    void Compiler::operator()(ast::VarDec& dec)
    {
        if (dec.exp_get())
            dec.exp_get()->accept(*this);

        if (local_)
        {
            int addr = var_scope_.get(dec.name_get());

            if (addr == INT_MIN)
                std::cerr << dec.location_get() << ": undefined reference to"
                          << dec.name_get() << std::endl;

            bytecode_.push_back(new bytecode::StoreLocal(dec.location_get(),
                                                         addr));
        }
        else
            bytecode_.push_back(new bytecode::StoreVar(dec.location_get(),
                                                       dec.name_get()));
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
} // namespace compile
