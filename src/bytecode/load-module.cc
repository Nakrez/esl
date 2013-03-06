#include <bytecode/load-module.hh>

namespace bytecode
{
    LoadModule::LoadModule(const yy::location& location,
                           const std::string& str)
        : Bytecode(location)
        , str_(str)
    {}

    LoadModule::~LoadModule()
    {}
} // namespace bytecode
