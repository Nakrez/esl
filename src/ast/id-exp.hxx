#ifndef ID_EXP_HXX
# define ID_EXP_HXX

# include <ast/visitor.hh>

# include <ast/id-exp.hh>

namespace ast
{
    inline void IdExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline const misc::symbol& IdExp::name_get() const
    {
        return name_;
    }
} // namespace ast

#endif /* !ID_EXP_HXX */
