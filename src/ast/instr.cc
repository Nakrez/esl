#include <ast/instr.hh>

namespace ast
{
    Instr::Instr(const yy::location& location)
        : Ast(location)
    {}

    Instr::~Instr()
    {}
} // namespace ast
