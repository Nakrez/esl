#include <ast/exp-list.hh>

namespace ast
{
    ExpList::ExpList(const yy::location& location)
        : Ast(location)
        , list_(new std::list<Exp*>)
    {}

    ExpList::ExpList(const yy::location& location,
                      std::list<Exp*>* list)
        : Ast(location)
        , list_(list)
    {}

    ExpList::~ExpList()
    {
        delete list_;
    }
} // namespace ast
