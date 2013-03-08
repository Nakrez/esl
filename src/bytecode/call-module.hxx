#ifndef CALL_MODULE_HXX
# define CALL_MODULE_HXX

# include <bytecode/call-module.hh>

namespace bytecode
{
    inline const misc::symbol& CallModule::name_get() const
    {
        return name_;
    }

    inline void CallModule::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !CALL_MODULE_HXX */
