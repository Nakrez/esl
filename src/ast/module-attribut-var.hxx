#ifndef MODULE_ATTRIBUT_VAR_HXX
# define MODULE_ATTRIBUT_VAR_HXX

# include <ast/module-attribut-var.hh>

namespace ast
{
    inline const Var* ModuleAttributVar::var_get() const
    {
        return var_;
    }

    inline Var* ModuleAttributVar::var_get()
    {
        return var_;
    }

    inline misc::symbol& ModuleAttributVar::name_get()
    {
        return name_;
    }

    inline const misc::symbol& ModuleAttributVar::name_get() const
    {
        return name_;
    }

    inline void ModuleAttributVar::accept(Visitor& visitor)
    {
        visitor(*this);
    }

} // namespace ast

#endif /* !MODULE_ATTRIBUT_VAR_HXX */
