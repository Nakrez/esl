#include <bytecode/load-float.hh>

namespace bytecode
{
    LoadFloat::LoadFloat(const yy::location& location,
                         float value)
        : Bytecode(location)
        , value_(value)
    {}

    LoadFloat::~LoadFloat()
    {}
} // namespace bytecode
