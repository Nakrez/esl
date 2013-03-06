#include <bytecode/open-module.hh>

namespace bytecode
{
    OpenModule::OpenModule(const yy::location& location,
                           const std::string& str)
        : Bytecode(location)
        , str_(str)
    {}

    OpenModule::~OpenModule()
    {}
} // namespace bytecode
