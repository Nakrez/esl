#include <bytecode/call-method.hh>

namespace bytecode
{
    CallMethod::CallMethod(const yy::location& location,
                           const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    CallMethod::~CallMethod()
    {}
} // namespace bytecode
