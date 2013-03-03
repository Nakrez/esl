#include <ast/continue-exp.hh>

namespace ast
{
    ContinueExp::ContinueExp(const yy::location& location)
        : Exp(location)
    {}

    ContinueExp::~ContinueExp()
    {}
} // namespace ast
