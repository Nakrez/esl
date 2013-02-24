#include <ast/else-instr.hh>

namespace ast
{
    ElseInstr::ElseInstr(const yy::location& location,
              InstrList* list)
        : Instr(location)
        , instr_list_(list)
    {}

    ElseInstr::~ElseInstr()
    {
        delete instr_list_;
    }
} // namespace ast
