#include <bytecode/bytecode.hh>

namespace bytecode
{
    Bytecode::Bytecode(const yy::location& location)
        : location_(location)
    {}

    Bytecode::~Bytecode()
    {}
} // namespace bytecode
