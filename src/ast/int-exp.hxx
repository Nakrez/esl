#ifndef INT_EXP_HXX
# define INT_EXP_HXX

# include <ast/visitor.hh>

# include <ast/int-exp.hh>

namespace ast
{
    inline void IntExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline int IntExp::value_get() const
    {
        return value_;
    }
} // namespace ast

#endif /* !INT_EXP_HXX */
