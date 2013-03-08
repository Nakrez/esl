#ifndef END_CLASS_HXX
# define END_CLASS_HXX

# include <bytecode/end-class.hh>

namespace bytecode
{
    inline void EndClass::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !END_CLASS_HXX */
