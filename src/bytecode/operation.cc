#include <bytecode/operation.hh>

const static std::string operator_string[] =
{
    "operator+",
    "operator-",
    "operator*",
    "operator/",
    "operator%",
    "operator^",
    "operator==",
    "operator!=",
    "operator>",
    "operator>=",
    "operator<",
    "operator<=",
    "operator||",
    "operator!"
};

namespace bytecode
{
    Operation::Operation(const yy::location& location,
                         ast::OpExp::Operator op)
        : Bytecode(location)
        , op_(op)
    {}

    Operation::~Operation()
    {}

    const std::string& Operation::string_op() const
    {
        return operator_string[op_];
    }
} // namespace bytecode
