#ifndef INHERIT_HXX
# define INHERIT_HXX

# include <bytecode/inherit.hh>

namespace bytecode
{
    inline const misc::symbol& Inherit::name_get() const
    {
        return name_;
    }

    inline void Inherit::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !INHERIT_HXX */
