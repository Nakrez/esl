#include <bytecode/open-module.hh>

namespace bytecode
{
    OpenModule::OpenModule(const yy::location& location,
                           int data)
        : Bytecode(location)
        , data_(data)
    {}

    OpenModule::~OpenModule()
    {}
} // namespace bytecode
