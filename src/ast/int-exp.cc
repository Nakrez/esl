#include <ast/int-exp.hh>

namespace ast
{
    IntExp::IntExp(const yy::location& location,
                   int value)
        : Exp(location)
        , value_(value)
    {}

    IntExp::~IntExp()
    {}
} // namespace ast
