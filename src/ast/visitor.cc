#include <ast/visitor.hh>
#include <ast/all.hh>

namespace ast
{
    Visitor::Visitor()
    {}

    Visitor::~Visitor()
    {}

    void Visitor::operator()(Ast& ast)
    {
        ast.accept(*this);
    }

    void Visitor::operator()(AstList& ast)
    {
        for (auto elem : ast.list_get())
            elem->accept(*this);
    }

    void Visitor::operator()(InstrList& ast)
    {
        for (auto elem : ast.list_get())
            elem->accept(*this);
    }

    void Visitor::operator()(DecList& ast)
    {
        for (auto elem : ast.list_get())
            elem->accept(*this);
    }

    void Visitor::operator()(VarDecList& ast)
    {
        for (auto elem : ast.list_get())
            elem->accept(*this);
    }
} // namespace ast
