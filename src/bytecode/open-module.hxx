#ifndef OPEN_MODULE_HXX
# define OPEN_MODULE_HXX

# include <bytecode/open-module.hh>

namespace bytecode
{
    inline const int& OpenModule::data_get() const
    {
        return data_;
    }

    inline int& OpenModule::data_get()
    {
        return data_;
    }

    inline void OpenModule::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !OPEN_MODULE_HXX */
