#ifndef CLASS_DEC_HXX
# define CLASS_DEC_HXX

# include <ast/class-dec.hh>

namespace ast
{
    inline const IdList* ClassDec::inherit_get() const
    {
        return inherit_;
    }

    inline IdList* ClassDec::inherit_get()
    {
        return inherit_;
    }

    inline const DecList* ClassDec::components_get() const
    {
        return components_;
    }

    inline DecList* ClassDec::components_get()
    {
        return components_;
    }

    inline void ClassDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void ClassDec::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !CLASS_DEC_HXX */
