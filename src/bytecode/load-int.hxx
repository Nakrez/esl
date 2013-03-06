#ifndef LOAD_INT_HXX
# define LOAD_INT_HXX

# include <bytecode/load-int.hh>

namespace bytecode
{
    inline int LoadInt::value_get() const
    {
        return value_;
    }

    inline void LoadInt::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_INT_HXX */
