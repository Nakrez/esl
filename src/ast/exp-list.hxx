#ifndef EXP_LIST_HXX
# define EXP_LIST_HXX

# include <ast/exp-list.hh>

namespace ast
{
    inline const std::list<Exp*>& ExpList::list_get() const
    {
        return *list_;
    }
} // namespace ast

#endif /* !EXP_LIST_HXX */
