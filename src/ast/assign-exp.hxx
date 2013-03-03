#ifndef ASSIGN_EXP_HXX
# define ASSIGN_EXP_HXX

# include <ast/assign-exp.hh>

namespace ast
{
    inline const Var* AssignExp::var_get() const
    {
        return var_;
    }

    inline Var* AssignExp::var_get()
    {
        return var_;
    }

    inline const Exp* AssignExp::exp_get() const
    {
        return exp_;
    }

    inline Exp* AssignExp::exp_get()
    {
        return exp_;
    }

    inline void AssignExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }
}

#endif /* !ASSIGN_EXP_HXX */
