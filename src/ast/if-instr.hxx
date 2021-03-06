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

    inline Exp* IfInstr::condition_get()
    {
        return condition_;
    }

    inline InstrList* IfInstr::exp_true_get()
    {
        return exp_true_;
    }

    inline Instr* IfInstr::exp_else_get()
    {
        return exp_else_;
    }

    inline void IfInstr::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void IfInstr::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !IF_INSTR_HXX */
