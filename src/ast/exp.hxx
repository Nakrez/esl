#ifndef EXP_HXX
# define EXP_HXX

# include <ast/exp.hh>

namespace ast
{
    Exp::Exp(const yy::location& location)
        : Ast(location)
    {}
}

#endif /* !EXP_HXX */
