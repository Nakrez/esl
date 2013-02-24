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
} // namespace ast
