#include <bytecode/load-attr.hh>

namespace bytecode
{
    LoadAttr::LoadAttr(const yy::location& location,
                       const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    LoadAttr::~LoadAttr()
    {}
} // namespace bytecode
