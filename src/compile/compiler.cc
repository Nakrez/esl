#include <compile/compiler.hh>
#include <ast/all.hh>

namespace compile
{
    Compiler::Compiler()
        : Visitor()
    {}

    Compiler::~Compiler()
    {}

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
    }

    void Compiler::operator()(ast::VarDec& dec)
    {
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
