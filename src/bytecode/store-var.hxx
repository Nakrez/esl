#ifndef STORE_VAR_HXX
# define STORE_VAR_HXX

# include <bytecode/store-var.hh>

namespace bytecode
{
    inline const misc::symbol& StoreVar::name_get() const
    {
        return name_;
    }

    inline void StoreVar::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !STORE_VAR_HXX */
