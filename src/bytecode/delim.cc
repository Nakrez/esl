#include <bytecode/delim.hh>

namespace bytecode
{
    Delim::Delim(const yy::location& location)
        : Bytecode(location)
    {}

    Delim::~Delim()
    {}
} // namespace bytecode
