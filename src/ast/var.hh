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

            virtual void accept(Visitor& visitor) = 0;
            virtual void accept(ConstVisitor& visitor) const = 0;
    };
} // namespace ast

#endif /* !VAR_HH */
