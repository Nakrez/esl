#ifndef POP_HXX
# define POP_HXX

# include <bytecode/pop.hh>

namespace bytecode
{
    inline void Pop::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !POP_HXX */
