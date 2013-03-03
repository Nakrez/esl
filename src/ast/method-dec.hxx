#ifndef METHOD_DEC_HXX
# define METHOD_DEC_HXX

# include <ast/method-dec.hh>

namespace ast
{
    inline misc::visibility MethodDec::visibility_get() const
    {
        return visibility_;
    }

    inline void MethodDec::visibility_set(misc::visibility visibility)
    {
        visibility_ = visibility;
    }

    inline void MethodDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !METHOD_DEC_HXX */
