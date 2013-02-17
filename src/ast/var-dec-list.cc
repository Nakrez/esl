#include <ast/var-dec-list.hh>

namespace ast
{
    VarDecList::VarDecList(const yy::location& location)
        : Ast(location)
        , list_(new std::list<VarDec*>)
    {}

    VarDecList::VarDecList(const yy::location& location,
                           std::list<VarDec*>* list)
        : Ast(location)
        , list_(list)
    {}

    VarDecList::~VarDecList()
    {
        delete list_;
    }
} // namespace ast
