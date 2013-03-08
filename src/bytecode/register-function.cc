#include <bytecode/register-function.hh>

namespace bytecode
{
    RegisterFunction::RegisterFunction(const yy::location& location,
                                       const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    RegisterFunction::~RegisterFunction()
    {}
} // namespace bytecode
