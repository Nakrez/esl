#ifndef EXP_HH
# define EXP_HH

# include <ast/ast>

namespace ast
{
    class Exp : public Ast
    {
        public:
            Exp(const yy::location& location);
    };
}// namespace ast

#endif /* !EXP_HH */
