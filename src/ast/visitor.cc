#include <ast/visitor.hh>
#include <ast/ast.hh>

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
