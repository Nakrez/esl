#include <ast/var.hh>

namespace ast
{
    Var::Var(const yy::location& location,
             const misc::symbol& name)
        : Exp(location)
        , name_(name)
    {}

    Var::~Var()
    {}
} // namespace ast
