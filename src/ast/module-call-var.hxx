#ifndef MODULE_CALL_VAR_HXX
# define MODULE_CALL_VAR_HXX

# include <ast/module-call-var.hh>

namespace ast
{
    inline const Var* ModuleCallVar::var_get() const
    {
        return var_;
    }

    inline Var* ModuleCallVar::var_get()
    {
        return var_;
    }

    inline const FunctionCallExp* ModuleCallVar::call_get() const
    {
        return call_;
    }

    inline FunctionCallExp* ModuleCallVar::call_get()
    {
        return call_;
    }

    inline void ModuleCallVar::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !MODULE_CALL_VAR_HXX */
