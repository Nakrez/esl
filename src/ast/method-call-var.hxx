#ifndef METHOD_CALL_VAR_HXX
# define METHOD_CALL_VAR_HXX

# include <ast/method-call-var.hh>

namespace ast
{
    inline Var* MethodCallVar::var_get()
    {
        return var_;
    }

    inline const Var* MethodCallVar::var_get() const
    {
        return var_;
    }

    inline const FunctionCallExp* MethodCallVar::call_get() const
    {
        return call_;
    }

    inline FunctionCallExp* MethodCallVar::call_get()
    {
        return call_;
    }

    inline void MethodCallVar::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void MethodCallVar::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !METHOD_CALL_VAR_HXX */
