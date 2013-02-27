#ifndef VAR_ID_HXX
# define VAR_ID_HXX

# include <ast/var-id.hh>

namespace ast
{
    inline void VarId::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline const misc::symbol& VarId::name_get() const
    {
        return name_;
    }
}

#endif /* !VAR_ID_HXX */
