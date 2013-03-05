#include <bytecode/store-attr.hh>

namespace bytecode
{
    StoreAttr::StoreAttr(const yy::location& location,
                       const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    StoreAttr::~StoreAttr()
    {}
} // namespace bytecode
