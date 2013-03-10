#ifndef JUMP_FALSE_HXX
# define JUMP_FALSE_HXX

# include <bytecode/jump-false.hh>

namespace bytecode
{
    inline void JumpFalse::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !JUMP_FALSE_HXX */
