#ifndef IF_INSTR_HXX
# define IF_INSTR_HXX

# include <ast/visitor.hh>

# include <ast/if-instr.hh>

namespace ast
{
    inline const Exp* IfInstr::condition_get() const
    {
        return condition_;
    }

    inline const InstrList* IfInstr::exp_true_get() const
    {
        return exp_true_;
    }

    inline const Instr* IfInstr::exp_else_get() const
    {
        return exp_else_;
    }

    inline void IfInstr::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !IF_INSTR_HXX */
