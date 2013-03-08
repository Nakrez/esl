#include <bytecode/inherit.hh>

namespace bytecode
{
    Inherit::Inherit(const yy::location& location,
                     const misc::symbol& name)
        : Bytecode(location)
        , name_(name)
    {}

    Inherit::~Inherit()
    {}
} // namespace bytecode
