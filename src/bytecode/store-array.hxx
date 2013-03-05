#ifndef STORE_ARRAY_HXX
# define STORE_ARRAY_HXX

# include <bytecode/store-array.hh>

namespace bytecode
{
    inline void StoreArray::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !STORE_ARRAY_HXX */
