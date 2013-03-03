#include <ast/new-exp.hh>

namespace ast
{
    NewExp::NewExp(const yy::location& location,
                   FunctionCallExp* exp)
        : Exp(location)
        , exp_(exp)
    {}

    NewExp::~NewExp()
    {
        delete exp_;
    }
} // namespace ast
