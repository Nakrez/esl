#ifndef CALL_MODULE_HXX
# define CALL_MODULE_HXX

# include <bytecode/call-module.hh>

namespace bytecode
{
    inline const int& CallModule::data_get() const
    {
        return data_;
    }

    inline int& CallModule::data_get()
    {
        return data_;
    }

    inline void CallModule::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !CALL_MODULE_HXX */
