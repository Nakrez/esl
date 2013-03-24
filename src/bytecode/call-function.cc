#include <bytecode/call-function.hh>

namespace bytecode
{
    CallFunction::CallFunction(const yy::location& location,
                               unsigned addr)
        : Bytecode(location)
        , addr_(addr)
    {}

    CallFunction::~CallFunction()
    {}
} // namespace bytecode
