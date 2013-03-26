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

    inline const Exp* AttributDec::value_get() const
    {
        return value_;
    }

    inline Exp* AttributDec::value_get()
    {
        return value_;
    }

    inline void AttributDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void AttributDec::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !ATTRIBUT_DEC_HXX */
