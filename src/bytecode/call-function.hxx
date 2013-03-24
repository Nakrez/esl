#ifndef CALL_FUNCTION_HXX
# define CALL_FUNCTION_HXX

# include <bytecode/call-function.hh>

namespace bytecode
{
    inline unsigned CallFunction::addr_get() const
    {
        return addr_;
    }

    inline void CallFunction::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !CALL_FUNCTION_HXX */
