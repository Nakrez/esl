#include <bytecode/new-object.hh>

namespace bytecode
{
    NewObject::NewObject(const yy::location& location,
                         const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    NewObject::~NewObject()
    {}
} // namespace bytecode
