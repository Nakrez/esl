#include <bytecode/jump-true.hh>

namespace bytecode
{
    JumpTrue::JumpTrue(const yy::location& location,
                       int offset)
        : Jump(location, offset)
    {}

    JumpTrue::~JumpTrue()
    {}
} // namespace bytecode
