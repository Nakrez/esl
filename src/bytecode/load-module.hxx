#ifndef LOAD_MODULE_HXX
# define LOAD_MODULE_HXX

# include <bytecode/load-module.hh>

namespace bytecode
{
    inline const std::string& LoadModule::str_get() const
    {
        return str_;
    }

    inline void LoadModule::accept(const Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_MODULE_HXX */
