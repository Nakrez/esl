#include <bytecode/jump-false.hh>

namespace bytecode
{
    JumpFalse::JumpFalse(const yy::location& location,
                         int offset)
        : Jump(location, offset)
    {}

    JumpFalse::~JumpFalse()
    {}
} // namespace bytecode
