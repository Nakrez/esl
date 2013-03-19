#ifndef LOAD_LOCAL_HXX
# define LOAD_LOCAL_HXX

# include <bytecode/load-local.hh>

namespace bytecode
{
    inline unsigned LoadLocal::addr_get() const
    {
        return addr_;
    }

    inline void LoadLocal::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_LOCAL_HXX */
