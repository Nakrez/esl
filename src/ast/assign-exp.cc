#include <ast/assign-exp.hh>

namespace ast
{
    AssignExp::AssignExp(const yy::location& location,
                         Var* var,
                         Exp* exp)
        : Exp(location)
        , var_(var)
        , exp_(exp)
    {}

    AssignExp::~AssignExp()
    {
        delete var_;
        delete exp_;
    }

} // namespace ast
