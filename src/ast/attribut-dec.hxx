#ifndef ATTRIBUT_DEC_HXX
# define ATTRIBUT_DEC_HXX

# include <ast/visitor.hh>

# include <ast/attribut-dec.hh>

namespace ast
{
    inline misc::visibility AttributDec::visibility_get() const
    {
        return visibility_;
    }

    inline void AttributDec::visibility_set(misc::visibility visibility)
    {
        visibility_ = visibility;
    }

    inline void AttributDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !ATTRIBUT_DEC_HXX */