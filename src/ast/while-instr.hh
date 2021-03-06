#ifndef WHILE_INSTR_HH
# define WHILE_INSTR_HH

# include <ast/fwd.hh>
# include <ast/any-list.hh>
# include <ast/instr.hh>
# include <ast/exp.hh>

namespace ast
{
    class WhileInstr : public Instr
    {
        public:
            WhileInstr(const yy::location& location,
                       Exp* condition,
                       InstrList* instr_list);
            virtual ~WhileInstr();

            const InstrList* instr_list_get() const;
            const Exp* condition_get() const;

            Exp* condition_get();
            InstrList* instr_list_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            Exp* condition_;
            InstrList* instr_list_;
    };
} // namespace ast

# include <ast/while-instr.hxx>

#endif /* !WHILE_INSTR_HH */
