#ifndef RETURN_HXX
# define RETURN_HXX

# include <bytecode/return.hh>

namespace bytecode
{
    inline void Return::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !RETURN_HXX */
