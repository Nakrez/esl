#ifndef REGISTER_FUNCTION_HXX
# define REGISTER_FUNCTION_HXX

# include <bytecode/register-function.hh>

namespace bytecode
{
    inline unsigned RegisterFunction::data_get() const
    {
        return data_;
    }

    inline void RegisterFunction::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !REGISTER_FUNCTION_HXX */
