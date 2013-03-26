#ifndef BREAK_EXP_HXX
# define BREAK_EXP_HXX

# include <ast/break-exp.hh>

namespace ast
{
    inline void BreakExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void BreakExp::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !BREAK_EXP_HXX */
