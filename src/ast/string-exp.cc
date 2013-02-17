#include <ast/string-exp.hh>

namespace ast
{
    StringExp::StringExp(const yy::location& location,
                         const std::string& value)
        : Exp(location)
        , value_(value)
    {}

    StringExp::~StringExp()
    {}
} // namespace ast
