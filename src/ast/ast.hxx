#ifndef AST_HXX
# define AST_HXX

# include <ast/visitor.hh>

# include <ast/ast.hh>

namespace ast
{
    inline const yy::location& Ast::location_get() const
    {
        return location_;
    }

    inline void Ast::location_set(const yy::location& location)
    {
        location_ = location;
    }
}

#endif /* !AST_HXX */
