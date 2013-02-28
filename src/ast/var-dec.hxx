#ifndef VAR_DEC_HXX
# define VAR_DEC_HXX

# include <ast/var-dec.hh>

namespace ast
{
    inline const Exp* VarDec::exp_get() const
    {
        return exp_;
    }

    inline Exp* VarDec::exp_get()
    {
        return exp_;
    }

    inline void VarDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !VAR_DEC_HXX */
