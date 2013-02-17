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
} // namespace ast
