/// date 17 Feb 2013
#ifndef EXP_HH
# define EXP_HH

# include <ast/ast.hh>

namespace ast
{
    class Exp : public Ast
    {
        public:
            Exp(const yy::location& location);
    };
}// namespace ast

#endif /* !EXP_HH */
