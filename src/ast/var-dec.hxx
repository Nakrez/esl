#ifndef VAR_DEC_HXX
# define VAR_DEC_HXX

# include <ast/var-dec.hh>

namespace ast
{
    inline Exp* VarDec::value_get() const
    {
        return value_;
    }

    inline void VarDec::value_set(Exp* value)
    {
        value_ = value;
    }

    inline void VarDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !VAR_DEC_HXX */
