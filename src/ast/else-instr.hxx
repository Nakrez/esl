#ifndef ELSE_INSTR_HXX
# define ELSE_INSTR_HXX

# include <ast/else-instr.hh>

namespace ast
{
    inline InstrList* ElseInstr::instr_list_get() const
    {
        return instr_list_;
    }

    inline void ElseInstr::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !ELSE_INSTR_HXX */
