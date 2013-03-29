#include <bytecode/load-module.hh>

namespace bytecode
{
    LoadModule::LoadModule(const yy::location& location,
                           int data)
        : Bytecode(location)
        , data_(data)
    {}

    LoadModule::~LoadModule()
    {}
} // namespace bytecode
