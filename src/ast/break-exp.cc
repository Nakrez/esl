#include <ast/break-exp.hh>

namespace ast
{
    BreakExp::BreakExp(const yy::location& location)
        : Exp(location)
    {}

    BreakExp::~BreakExp()
    {}
} // namespace ast
