#include <ast/array-var.hh>

namespace ast
{
    ArrayVar::ArrayVar(const yy::location& location,
                       Var* var,
                       Exp* exp)
        : Var(location)
        , var_(var)
        , exp_(exp)
    {}

    ArrayVar::~ArrayVar()
    {
        delete var_;
        delete exp_;
    }
} // namespace ast
