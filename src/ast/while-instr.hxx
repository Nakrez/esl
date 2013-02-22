#ifndef WHILE_INSTR_HXX
# define WHILE_INSTR_HXX

# include <ast/while-instr.hh>

namespace ast
{
    inline const InstrList* WhileInstr::instr_list_get() const
    {
        return instr_list_;
    }

    inline const Exp* WhileInstr::condition_get() const
    {
        return condition_;
    }

    inline void WhileInstr::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !WHILE_INSTR_HXX */
