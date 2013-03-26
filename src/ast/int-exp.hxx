#ifndef INT_EXP_HXX
# define INT_EXP_HXX

# include <ast/visitor.hh>

# include <ast/int-exp.hh>

namespace ast
{
    inline const int& IntExp::value_get() const
    {
        return value_;
    }

    inline int& IntExp::value_get()
    {
        return value_;
    }

    inline void IntExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void IntExp::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !INT_EXP_HXX */
