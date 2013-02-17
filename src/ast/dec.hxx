#ifndef DEC_HXX
# define DEC_HXX

# include <ast/dec.hh>

namespace ast
{
    Dec::Dec(const yy::location& location,
             const misc::symbol& name)
        : Ast(location)
        , name_(name)
    {
    }

    inline const misc::symbol& name_get() const
    {
        return name_;
    }

    inline void name_set(const misc::symbol& name)
    {
        name_ = name;
    }
} // namespace ast

#endif /* !DEC_HXX */
