#include <ast/dec.hh>

namespace ast
{
    Dec::Dec(const yy::location& location,
             const misc::symbol& name)
        : Var(location, name)
    {}

    Dec::~Dec()
    {}
} // namespace ast
