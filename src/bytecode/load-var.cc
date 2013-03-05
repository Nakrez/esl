#include <bytecode/load-var.hh>

namespace bytecode
{
    LoadVar::LoadVar(const yy::location& location,
                     const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    LoadVar::~LoadVar()
    {}
} // namespace bytecode
