#include <bytecode/register-attribut.hh>

namespace bytecode
{
    RegisterAttribut::RegisterAttribut(const yy::location& location,
                                       const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    RegisterAttribut::~RegisterAttribut()
    {}
} // namespace bytecode
