#ifndef VAR_HH
# define VAR_HH

# include <ast/exp.hh>
# include <misc/symbol.hh>

namespace ast
{
    class Var : public Exp
    {
        public:
            Var(const yy::location& location);
            virtual ~Var();
    };
} // namespace ast

#endif /* !VAR_HH */
