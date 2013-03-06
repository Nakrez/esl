#ifndef LOAD_ATTR_HXX
# define LOAD_ATTR_HXX

# include <bytecode/load-attr.hh>

namespace bytecode
{
    inline const misc::symbol& LoadAttr::name_get() const
    {
        return name_;
    }

    inline void LoadAttr::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_ATTR_HXX */
