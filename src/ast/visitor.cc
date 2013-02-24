#include <ast/visitor.hh>
#include <ast/list.hh>

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

    void Visitor::operator()(AnyList<Instr>& list)
    {
        for (auto elem : list.list_get())
        {
            elem->accept(*this);
        }
    }
} // namespace ast
