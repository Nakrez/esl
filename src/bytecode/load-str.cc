#include <bytecode/load-str.hh>

namespace bytecode
{
    LoadStr::LoadStr(const yy::location& location,
                     int data)
        : Bytecode(location)
        , data_(data)
    {}

    LoadStr::~LoadStr()
    {}
} // namespace bytecode
