#ifndef CONTINUE_EXP_HH
# define CONTINUE_EXP_HH

# include <ast/exp.hh>

namespace ast
{
    class ContinueExp : public Exp
    {
        public:
            ContinueExp(const yy::location& location);
            ~ContinueExp();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;
    };
} // namespace ast

# include <ast/continue-exp.hxx>

#endif /* !CONTINUE_EXP_HH */
