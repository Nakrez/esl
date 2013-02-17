#ifndef DEC_HXX
# define DEC_HXX

# include <ast/dec.hh>

namespace ast
{
    inline const misc::symbol& Dec::name_get() const
    {
        return name_;
    }

    inline void Dec::name_set(const misc::symbol& name)
    {
        name_ = name;
    }
} // namespace ast

#endif /* !DEC_HXX */
