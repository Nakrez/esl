#ifndef INSTR_LIST_HXX
# define INSTR_LIST_HXX

# include <ast/instr-list.hh>

namespace ast
{
    inline void InstrList::push_back(Instr* i)
    {
        instr_list_.push_back(i);
    }

    inline const std::list<Instr*>& InstrList::instr_list_get()
    {
        return instr_list_;
    }
} // namespace ast

#endif /* !INSTR_LIST_HXX */
