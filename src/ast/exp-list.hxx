#ifndef EXP_LIST_HXX
# define EXP_LIST_HXX

# include <ast/visitor.hh>

# include <ast/exp-list.hh>

namespace ast
{
    inline const std::list<Exp*>& ExpList::list_get() const
    {
        return *list_;
    }

    inline void ExpList::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !EXP_LIST_HXX */
