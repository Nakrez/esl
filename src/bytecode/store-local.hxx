#ifndef STORE_LOCAL_HXX
# define STORE_LOCAL_HXX

# include <bytecode/store-local.hh>

namespace bytecode
{
    inline unsigned StoreLocal::addr_get() const
    {
        return addr_;
    }

    inline void StoreLocal::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !STORE_LOCAL_HXX */
