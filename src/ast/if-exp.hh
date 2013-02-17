/// date 17 Feb 2013
#ifndef IF_EXP_HH
# define IF_EXP_HH

# include <ast/exp.hh>

namespace ast
{
    class IfExp : public Exp
    {
        public:
            IfExp(const yy::location& location,
                  Exp* condition,
                  Exp* exp_true);
            IfExp(const yy::location& location,
                  Exp* condition,
                  Exp* exp_true,
                  Exp* exp_else);
            ~IfExp();

            const Exp* condition_get() const;
            const Exp* exp_true_get() const;
            const Exp* exp_else_get() const;

            virtual void accept(Visitor& visitor);

        protected:
            Exp* condition_;
            Exp* exp_true_;
            Exp* exp_else_;
    };
} // namespace ast

# include <ast/if-exp.hxx>

#endif /* !IF_EXP_HH */
