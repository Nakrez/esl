#include <bytecode/load-local.hh>

namespace bytecode
{
    LoadLocal::LoadLocal(const yy::location& location,
                         unsigned addr)
        : Bytecode(location)
        , addr_(addr)
    {}

    LoadLocal::~LoadLocal()
    {}
} // namespace bytecode
