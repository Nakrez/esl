#ifndef REGISTER_ATTRIBUT_HXX
# define REGISTER_ATTRIBUT_HXX

# include <bytecode/register-attribut.hh>

namespace bytecode
{
    inline const misc::symbol& RegisterAttribut::name_get() const
    {
        return name_;
    }

    inline void RegisterAttribut::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !REGISTER_ATTRIBUT_HXX */
