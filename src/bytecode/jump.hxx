#ifndef JUMP_HXX
# define JUMP_HXX

# include <bytecode/jump.hh>

namespace bytecode
{
    inline int Jump::offset_get() const
    {
        return offset_;
    }

    inline void Jump::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !JUMP_HXX */
