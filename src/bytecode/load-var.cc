#include <bytecode/load-var.hh>

namespace bytecode
{
    LoadVar::LoadVar(const yy::location& location,
                     unsigned addr)
        : Bytecode(location)
        , addr_(addr)
    {}

    LoadVar::~LoadVar()
    {}
} // namespace bytecode
