#ifndef CALL_FUNCTION_HXX
# define CALL_FUNCTION_HXX

# include <bytecode/call-function.hh>

namespace bytecode
{
    inline const misc::symbol& CallFunction::name_get() const
    {
        return name_;
    }

    inline void CallFunction::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !CALL_FUNCTION_HXX */
