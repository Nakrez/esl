#ifndef JUMP_TRUE_HXX
# define JUMP_TRUE_HXX

# include <bytecode/jump-true.hh>

namespace bytecode
{
    inline void JumpTrue::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !JUMP_TRUE_HXX */
