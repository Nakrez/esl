#ifndef IF_EXP_HXX
# define IF_EXP_HXX

# include <ast/visitor.hh>

# include <ast/if-exp.hh>

namespace ast
{
    inline const Exp* IfExp::condition_get() const
    {
        return condition_;
    }

    inline const Exp* IfExp::exp_true_get() const
    {
        return exp_true_;
    }

    inline const Exp* IfExp::exp_else_get() const
    {
        return exp_else_;
    }

    inline void IfExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !IF_EXP_HXX */
