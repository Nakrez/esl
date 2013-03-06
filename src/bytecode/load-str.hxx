#ifndef LOAD_STR_HXX
# define LOAD_STR_HXX

# include <bytecode/load-str.hh>

namespace bytecode
{
    inline const std::string& LoadStr::str_get() const
    {
        return str_;
    }

    inline void LoadStr::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_STR_HXX */
