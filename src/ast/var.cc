#include <ast/var.hh>

namespace ast
{
    Var::Var(const yy::location& location)
        : Exp(location)
    {}

    Var::~Var()
    {}
} // namespace ast
