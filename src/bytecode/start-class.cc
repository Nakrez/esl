#include <bytecode/start-class.hh>

namespace bytecode
{
    StartClass::StartClass(const yy::location& location,
                           const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    StartClass::~StartClass()
    {}
} // namespace bytecode
