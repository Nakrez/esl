#include <bytecode/call-module.hh>

namespace bytecode
{
    CallModule::CallModule(const yy::location& location,
                           int data)
        : Bytecode(location)
        , data_(data)
    {}

    CallModule::~CallModule()
    {}
} // namespace bytecode
