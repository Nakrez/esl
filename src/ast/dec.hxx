#ifndef DEC_HXX
# define DEC_HXX

# include <ast/dec.hh>

namespace ast
{
    inline const misc::symbol& Dec::name_get() const
    {
        return name_;
    }

    inline misc::symbol& Dec::name_get()
    {
        return name_;
    }
} // namespace ast

#endif /* !DEC_HXX */
