#include <bytecode/store-var.hh>

namespace bytecode
{
    StoreVar::StoreVar(const yy::location& location,
                       int data)
        : Bytecode(location)
        , data_(data)
    {}

    StoreVar::~StoreVar()
    {}
} // namespace bytecode
