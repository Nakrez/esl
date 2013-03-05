#include <bytecode/store-var.hh>

namespace bytecode
{
    StoreVar::StoreVar(const yy::location& location,
                       const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    StoreVar::~StoreVar()
    {}
} // namespace bytecode
