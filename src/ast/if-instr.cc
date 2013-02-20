#include <ast/if-instr.hh>

namespace ast
{
    IfInstr::IfInstr(const yy::location& location,
                     Exp* condition,
                     Exp* exp_true)
        : Instr(location)
        , condition_(condition)
        , exp_true_(exp_true)
        , exp_else_(nullptr)
    {}

    IfInstr::IfInstr(const yy::location& location,
                     Exp* condition,
                     Exp* exp_true,
                     Exp* exp_else)
        : Instr(location)
        , condition_(condition)
        , exp_true_(exp_true)
        , exp_else_(exp_else)
    {}

    IfInstr::~IfInstr()
    {
        delete condition_;
        delete exp_true_;

        if (exp_else_)
            delete exp_else_;
    }
} // namespace ast
