#ifndef CONTINUE_EXP_HXX
# define CONTINUE_EXP_HXX

# include <ast/continue-exp.hh>

namespace ast
{
    inline void ContinueExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !CONTINUE_EXP_HXX */
