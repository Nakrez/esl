/// date 17 Feb 2013
#ifndef IF_INSTR_HH
# define IF_INSTR_HH

# include <ast/fwd.hh>
# include <ast/exp.hh>
# include <ast/any-list.hh>
# include <ast/instr.hh>

namespace ast
{
    class IfInstr : public Instr
    {
        public:
            IfInstr(const yy::location& location,
                    Exp* condition,
                    InstrList* exp_true);
            IfInstr(const yy::location& location,
                    Exp* condition,
                    InstrList* exp_true,
                    Instr* exp_else);
            virtual ~IfInstr();

            const Exp* condition_get() const;
            const InstrList* exp_true_get() const;
            const Instr* exp_else_get() const;

            Exp* condition_get();
            InstrList* exp_true_get();
            Instr* exp_else_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            Exp* condition_;
            InstrList* exp_true_;
            Instr* exp_else_;
    };
} // namespace ast

# include <ast/if-instr.hxx>

#endif /* !IF_INSTR_HH */
