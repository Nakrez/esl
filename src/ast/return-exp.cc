#include <ast/return-exp.hh>

namespace ast
{
    ReturnExp::ReturnExp(const yy::location& location, Exp* exp)
        : Exp(location)
        , exp_(exp)
    {}

    ReturnExp::~ReturnExp()
    {
        delete exp_;
    }
} // namespace ast
