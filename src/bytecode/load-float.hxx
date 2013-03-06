#ifndef LOAD_FLOAT_HXX
# define LOAD_FLOAT_HXX

# include <bytecode/load-float.hh>

namespace bytecode
{
    inline float LoadFloat::value_get() const
    {
        return value_;
    }

    inline void LoadFloat::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_FLOAT_HXX */
