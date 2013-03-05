#include <bytecode/bracket-op.hh>

namespace bytecode
{
    BracketOp::BracketOp(const yy::location& location)
        : Bytecode(location)
    {}

    BracketOp::~BracketOp()
    {}
} // namespace bytecode
