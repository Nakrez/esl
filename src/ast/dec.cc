#include <ast/dec.hh>

namespace ast
{
    Dec::Dec(const yy::location& location,
             const misc::symbol& name)
        : Ast(location)
    {
        name_ = name;
    }

    Dec::~Dec()
    {}
} // namespace ast
