#ifndef BREAK_EXP_HH
# define BREAK_EXP_HH

# include <ast/exp.hh>

namespace ast
{
    class BreakExp : public Exp
    {
        public:
            BreakExp(const yy::location& location);
            ~BreakExp();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;
    };
} // namespace ast

# include <ast/break-exp.hxx>

#endif /* !BREAK_EXP_HH */
