/// date 17 Feb 2013
#ifndef IF_INSTR_HH
# define IF_INSTR_HH

# include <ast/exp.hh>
# include <ast/instr.hh>

namespace ast
{
    class IfInstr : public Instr
    {
        public:
            IfInstr(const yy::location& location,
                    Exp* condition,
                    Exp* exp_true);
            IfInstr(const yy::location& location,
                    Exp* condition,
                    Exp* exp_true,
                    Exp* exp_else);
            ~IfInstr();

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

# include <ast/if-instr.hxx>

#endif /* !IF_INSTR_HH */
