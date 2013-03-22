#ifndef STORE_VAR_HXX
# define STORE_VAR_HXX

# include <bytecode/store-var.hh>

namespace bytecode
{
    inline int StoreVar::data_get() const
    {
        return data_;
    }

    inline void StoreVar::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !STORE_VAR_HXX */
