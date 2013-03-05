#include <bytecode/store-array.hh>

namespace bytecode
{
    StoreArray::StoreArray(const yy::location& location)
        : Bytecode(location)
    {}

    StoreArray::~StoreArray()
    {}
} // namespace bytecode
