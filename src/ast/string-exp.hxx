#ifndef STRING_EXP_HXX
# define STRING_EXP_HXX

# include <ast/visitor.hh>

# include <ast/string-exp.hh>

namespace ast
{
    inline const std::string& StringExp::value_get() const
    {
        return value_;
    }

    inline std::string& StringExp::value_get()
    {
        return value_;
    }

    inline void StringExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void StringExp::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !STRING_EXP_HXX */
