#include <bytecode/load-int.hh>

namespace bytecode
{
    LoadInt::LoadInt(const yy::location& location,
                     int value)
        : Bytecode(location)
        , value_(value)
    {}

    LoadInt::~LoadInt()
    {}
} // namespace bytecode
