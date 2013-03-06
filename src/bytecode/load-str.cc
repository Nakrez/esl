#include <bytecode/load-str.hh>

namespace bytecode
{
    LoadStr::LoadStr(const yy::location& location,
                     const std::string& str)
        : Bytecode(location)
        , str_(str)
    {}

    LoadStr::~LoadStr()
    {}
} // namespace bytecode
