#ifndef WHILE_INSTR_HH
# define WHILE_INSTR_HH

# include <ast/visitor.hh>
# include <ast/instr.hh>
# include <ast/exp.hh>
# include <ast/list.hh>

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
            void accept(Visitor& visitor);

        protected:
            Exp* condition_;
            InstrList* instr_list_;
    };
} // namespace ast

# include <ast/while-instr.hxx>

#endif /* !WHILE_INSTR_HH */
