#ifndef ELSE_INSTR_HH
# define ELSE_INSTR_HH

# include <ast/visitor.hh>
# include <ast/list.hh>

namespace ast
{
    class ElseInstr : public Instr
    {
        public:
            ElseInstr(const yy::location& location,
                      InstrList* list);
            virtual ~ElseInstr();

            InstrList* instr_list_get() const;

            void accept(Visitor& visitor);

        protected:
            InstrList* instr_list_;
    };
} // namespace ast

# include <ast/else-instr.hxx>

#endif /* !ELSE_INSTR_HH */
