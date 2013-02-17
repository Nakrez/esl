#ifndef VAR_DEC_LIST_HXX
# define VAR_DEC_LIST_HXX

# include <ast/var-dec-list.hh>

namespace ast
{
    inline const std::list<VarDec*>& VarDecList::list_get() const
    {
        return *list_;
    }
} // namespace ast

#endif /* !VAR_DEC_LIST_HXX */
