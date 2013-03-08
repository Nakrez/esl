#include <bytecode/call-function.hh>

namespace bytecode
{
    CallFunction::CallFunction(const yy::location& location,
                               const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    CallFunction::~CallFunction()
    {}
} // namespace bytecode
