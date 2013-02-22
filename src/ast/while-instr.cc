#include <ast/while-instr.hh>

namespace ast
{
    WhileInstr::WhileInstr(const yy::location& location,
                           Exp* condition,
                           InstrList* instr_list)
        : Instr(location)
        , condition_(condition)
        , instr_list_(instr_list)
    {}

    WhileInstr::~WhileInstr()
    {
        delete instr_list_;
    }
} // namespace ast
