#ifndef LOAD_STR_HXX
# define LOAD_STR_HXX

# include <bytecode/load-str.hh>

namespace bytecode
{
    inline int LoadStr::data_get() const
    {
        return data_;
    }

    inline void LoadStr::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_STR_HXX */
