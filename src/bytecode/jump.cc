#include <bytecode/jump.hh>

namespace bytecode
{
    Jump::Jump(const yy::location& location,
               int offset)
        : Bytecode(location)
        , offset_(offset)
    {}

    Jump::~Jump()
    {}
} // namespace bytecode
