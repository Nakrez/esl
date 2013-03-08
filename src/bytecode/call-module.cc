#include <bytecode/call-module.hh>

namespace bytecode
{
    CallModule::CallModule(const yy::location& location,
                           const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    CallModule::~CallModule()
    {}
} // namespace bytecode
