#ifndef CALL_METHOD_HXX
# define CALL_METHOD_HXX

# include <bytecode/call-method.hh>

namespace bytecode
{
    inline const misc::symbol& CallMethod::name_get() const
    {
        return name_;
    }

    inline void CallMethod::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !CALL_METHOD_HXX */
