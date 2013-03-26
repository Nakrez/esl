#ifndef VAR_ID_HXX
# define VAR_ID_HXX

# include <ast/var-id.hh>

namespace ast
{
    inline const misc::symbol& VarId::name_get() const
    {
        return name_;
    }

    inline misc::symbol& VarId::name_get()
    {
        return name_;
    }

    inline void VarId::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void VarId::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
}

#endif /* !VAR_ID_HXX */
