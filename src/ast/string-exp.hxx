#ifndef STRING_EXP_HXX
# define STRING_EXP_HXX

# include <ast/visitor.hh>

# include <ast/string-exp.hh>

namespace ast
{
    inline void StringExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline const std::string& StringExp::value_get() const
    {
        return value_;
    }
} // namespace ast

#endif /* !STRING_EXP_HXX */
