#include <ast/any-list.hh>

namespace ast
{
    template<class T>
    AnyList<T>::AnyList(const yy::location& location)
        : Ast(location)
    {}
} // namespace ast
