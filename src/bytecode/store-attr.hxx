#ifndef STORE_ATTR_HXX
# define STORE_ATTR_HXX

# include <bytecode/store-attr.hh>

namespace bytecode
{
    inline const misc::symbol& StoreAttr::name_get() const
    {
        return name_;
    }

    inline void StoreAttr::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !STORE_ATTR_HXX */
