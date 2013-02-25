#ifndef ELSE_INSTR_HH
# define ELSE_INSTR_HH

# include <ast/fwd.hh>
# include <ast/visitor.hh>
# include <ast/any-list.hh>
# include <ast/instr.hh>

namespace ast
{
    class ElseInstr : public Instr
    {
        public:
            ElseInstr(const yy::location& location,
                      InstrList* list);
            virtual ~ElseInstr();

            const InstrList* instr_list_get() const;
            InstrList* instr_list_get();

            void accept(Visitor& visitor);

        protected:
            InstrList* instr_list_;
    };
} // namespace ast

# include <ast/else-instr.hxx>

#endif /* !ELSE_INSTR_HH */
