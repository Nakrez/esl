#ifndef OP_EXP_HXX
# define OP_EXP_HXX

# include <ast/visitor.hh>

# include <ast/op-exp.hh>

namespace ast
{
    inline const Exp* OpExp::lop_get() const
    {
        return lop_;
    }

    inline const Exp* OpExp::rop_get() const
    {
        return rop_;
    }

    inline Exp* OpExp::lop_get()
    {
        return lop_;
    }

    inline Exp* OpExp::rop_get()
    {
        return rop_;
    }
    inline OpExp::Operator OpExp::op_get() const
    {
        return op_;
    }

    inline void OpExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !OP_EXP_HXX */
