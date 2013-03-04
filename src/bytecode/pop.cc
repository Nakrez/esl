#include <bytecode/pop.hh>

namespace bytecode
{
    Pop::Pop(const yy::location& location)
        : Bytecode(location)
    {}

    Pop::~Pop()
    {}
} // namespace bytecode
