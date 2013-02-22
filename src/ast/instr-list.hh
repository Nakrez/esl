#ifndef INSTR_LIST_HH
# define INSTR_LIST_HH

# include <ast/instr.hh>

namespace ast
{
    class InstrList : public Instr
    {
        public:
            InstrList(const yy::location& location);
            InstrList(const yy::location& location,
                      Instr* instr);

            void push_back(Instr*);
            const std::list<Instr*>& instr_list_get();

            void accept(Visitor& visitor);

        protected:
            std::list<Instr*> instr_list_;
    };
} // namespace ast

# include <ast/instr-list.hxx>

#endif /* !INSTR_LIST_HH */
