#ifndef OPEN_MODULE_HXX
# define OPEN_MODULE_HXX

# include <bytecode/open-module.hh>

namespace bytecode
{
    inline const std::string& OpenModule::str_get() const
    {
        return str_;
    }

    inline void OpenModule::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !OPEN_MODULE_HXX */
