#ifndef VAR_HXX
# define VAR_HXX

# include <ast/var.hh>

namespace ast
{
    inline const misc::symbol& Var::name_get() const
    {
        return name_;
    }
} // namespace ast

#endif /* !VAR_HXX */
