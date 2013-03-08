#ifndef REGISTER_FUNCTION_HXX
# define REGISTER_FUNCTION_HXX

# include <bytecode/register-function.hh>

namespace bytecode
{
    inline const misc::symbol& RegisterFunction::name_get() const
    {
        return name_;
    }

    inline void RegisterFunction::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !REGISTER_FUNCTION_HXX */
