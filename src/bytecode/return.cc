#include <bytecode/return.hh>

namespace bytecode
{
    Return::Return(const yy::location& location)
        : Bytecode(location)
    {}

    Return::~Return()
    {}
} // namespace bytecode
