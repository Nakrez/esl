#include <ast/if-exp.hh>

namespace ast
{
    IfExp::IfExp(const yy::location& location,
                 Exp* condition,
                 Exp* exp_true)
        : Exp(location)
        , condition_(condition)
        , exp_true_(exp_true)
        , exp_else_(nullptr)
    {}

    IfExp::IfExp(const yy::location& location,
                 Exp* condition,
                 Exp* exp_true,
                 Exp* exp_else)
        : Exp(location)
        , condition_(condition)
        , exp_true_(exp_true)
        , exp_else_(exp_else)
    {}

    IfExp::~IfExp()
    {
        delete condition_;
        delete exp_true_;

        if (exp_else_)
            delete exp_else_;
    }
} // namespace ast
