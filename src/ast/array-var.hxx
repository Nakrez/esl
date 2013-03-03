#ifndef ARRAY_VAR_HXX
# define ARRAY_VAR_HXX

# include <ast/array-var.hh>

namespace ast
{
    inline const Var* ArrayVar::var_get() const
    {
        return var_;
    }

    inline Var* ArrayVar::var_get()
    {
        return var_;
    }

    inline const Exp* ArrayVar::exp_get() const
    {
        return exp_;
    }

    inline Exp* ArrayVar::exp_get()
    {
        return exp_;
    }

    inline void ArrayVar::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !ARRAY_VAR_HXX */
