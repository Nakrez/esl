#ifndef LOAD_VAR_HXX
# define LOAD_VAR_HXX

# include <bytecode/load-var.hh>

namespace bytecode
{
    inline unsigned LoadVar::addr_get() const
    {
        return addr_;
    }

    inline void LoadVar::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_VAR_HXX */
