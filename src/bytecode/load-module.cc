#include <bytecode/load-module.hh>

namespace bytecode
{
    LoadModule::LoadModule(const yy::location& location,
                           const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    LoadModule::~LoadModule()
    {}
} // namespace bytecode
