#ifndef ATTRIBUT_VAR_HXX
# define ATTRIBUT_VAR_HXX

# include <ast/attribut-var.hh>

namespace ast
{
    inline const Var& AttributVar::call_var_get() const
    {
        return *call_var_;
    }

    inline Var& AttributVar::call_var_get()
    {
        return *call_var_;
    }

    inline const misc::symbol& AttributVar::name_get() const
    {
        return name_;
    }

    inline void AttributVar::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !ATTRIBUT_VAR_HXX */
