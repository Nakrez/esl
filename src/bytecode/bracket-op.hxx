#ifndef BRACKET_OP_HXX
# define BRACKET_OP_HXX

# include <bytecode/bracket-op.hh>

namespace bytecode
{
    inline void BracketOp::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !BRACKET_OP_HXX */
