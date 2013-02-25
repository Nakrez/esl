#include <ast/op-exp.hh>

namespace ast
{
    OpExp::OpExp(const yy::location location,
                 Exp* lop,
                 OpExp::Operator op,
                 Exp* rop)
        : Exp(location)
        , lop_(lop)
        , op_(op)
        , rop_(rop)
    {}

    OpExp::~OpExp()
    {
        delete lop_;
        delete rop_;
    }

    std::string OpExp::str_op() const
    {
        switch(op_)
        {
            case OpExp::add:
                return "+";
            case OpExp::min:
                return "-";
            case OpExp::tim:
                return "*";
            case OpExp::div:
                return "/";
            case OpExp::mod:
                return "%";
            case OpExp::pow:
                return "^";
            case OpExp::eq:
                return "==";
            case OpExp::neq:
                return "!=";
            case OpExp::gt:
                return ">";
            case OpExp::ge:
                return ">=";
            case OpExp::lt:
                return "<";
            case OpExp::le:
                return "<=";
            case OpExp::or_:
                return "||";
            case OpExp::and_:
                return "&&";
            case OpExp::not_:
                return "!";
            default:
                return "";
        }
    }
} // namespace ast
