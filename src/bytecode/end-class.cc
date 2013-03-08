#include <bytecode/end-class.hh>

namespace bytecode
{
    EndClass::EndClass(const yy::location& location)
        : Bytecode(location)
    {}

    EndClass::~EndClass()
    {}
} // namespace bytecode
