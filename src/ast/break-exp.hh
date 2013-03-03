#ifndef BREAK_EXP_HH
# define BREAK_EXP_HH

# include <ast/visitor.hh>
# include <ast/exp.hh>

namespace ast
{
    class BreakExp : public Exp
    {
        public:
            BreakExp(const yy::location& location);
            ~BreakExp();

            void accept(Visitor& visitor);
    };
} // namespace ast

# include <ast/break-exp.hxx>

#endif /* !BREAK_EXP_HH */
