#ifndef RETURN_EXP_HXX
# define RETURN_EXP_HXX

# include <ast/return-exp.hh>

namespace ast
{
    inline const Exp* ReturnExp::exp_get() const
    {
        return exp_;
    }

    inline Exp* ReturnExp::exp_get()
    {
        return exp_;
    }

    inline void ReturnExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !RETURN_EXP_HXX */
