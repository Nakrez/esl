#include <bytecode/register-function.hh>

namespace bytecode
{
    RegisterFunction::RegisterFunction(const yy::location& location,
                                       unsigned data)
        : Bytecode(location)
        , data_(data)
    {}

    RegisterFunction::~RegisterFunction()
    {}
} // namespace bytecode
