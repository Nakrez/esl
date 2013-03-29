#ifndef LOAD_MODULE_HXX
# define LOAD_MODULE_HXX

# include <bytecode/load-module.hh>

namespace bytecode
{
    inline const int& LoadModule::data_get() const
    {
        return data_;
    }

    inline int& LoadModule::data_get()
    {
        return data_;
    }

    inline void LoadModule::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !LOAD_MODULE_HXX */
