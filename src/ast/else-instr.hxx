#ifndef ELSE_INSTR_HXX
# define ELSE_INSTR_HXX

# include <ast/else-instr.hh>

namespace ast
{
    inline const InstrList* ElseInstr::instr_list_get() const
    {
        return instr_list_;
    }

    inline InstrList* ElseInstr::instr_list_get()
    {
        return instr_list_;
    }

    inline void ElseInstr::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void ElseInstr::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !ELSE_INSTR_HXX */
