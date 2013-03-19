#include <bytecode/store-local.hh>

namespace bytecode
{
    StoreLocal::StoreLocal(const yy::location& location,
                          unsigned addr)
        : Bytecode(location)
        , addr_(addr)
    {}

    StoreLocal::~StoreLocal()
    {}
} // namespace bytecode
