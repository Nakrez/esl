#ifndef NEW_EXP_HXX
# define NEW_EXP_HXX

# include <ast/new-exp.hh>

namespace ast
{
    inline const FunctionCallExp* NewExp::exp_get() const
    {
        return exp_;
    }

    inline FunctionCallExp* NewExp::exp_get()
    {
        return exp_;
    }

    inline void NewExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void NewExp::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !NEW_EXP_HXX */
