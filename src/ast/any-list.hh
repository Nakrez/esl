#ifndef ANY_LIST_HH
# define ANY_LIST_HH

# include <ast/ast.hh>

namespace ast
{
    template<class T>
    class AnyList : public Ast
    {
        public:
            AnyList(const yy::location& location);
    };
} // namespace ast

# include <ast/any-list.hh>

#endif /* !ANY_LIST_HH */
