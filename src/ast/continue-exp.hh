#ifndef CONTINUE_EXP_HH
# define CONTINUE_EXP_HH

# include <ast/visitor.hh>
# include <ast/exp.hh>

namespace ast
{
    class ContinueExp : public Exp
    {
        public:
            ContinueExp(const yy::location& location);
            ~ContinueExp();

            void accept(Visitor& visitor);
    };
} // namespace ast

# include <ast/continue-exp.hxx>

#endif /* !CONTINUE_EXP_HH */
