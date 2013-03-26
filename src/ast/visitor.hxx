/// @date 26/03/2013

#ifndef AST_VISITOR_HXX
# define AST_VISITOR_HXX

# include <ast/visitor.hh>

namespace ast
{
    template <template <typename> class Constness>
    GenVisitor<Constness>::~GenVisitor()
    {}

    template <template <typename> class Constness>
    void GenVisitor<Constness>::operator()(typename Constness<Ast>::type& a)
    {
        a.accept(*this);
    }

    template <template <typename> class Constness>
    template <typename A>
    void GenVisitor<Constness>::visit(A* a)
    {
        if (a)
            a->accept(*this);
    }

    template <template <typename> class Constness>
    template <typename A>
    void GenVisitor<Constness>::visit(typename Constness<A>::type& a)
    {
        a.accept(*this);
    }
} // namespace ast

#endif /* !AST_VISITOR_HXX */
