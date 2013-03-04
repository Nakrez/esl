#include <bytecode/visitor.hh>
#include <bytecode/all.hh>

namespace bytecode
{
    Visitor::Visitor()
    {}

    Visitor::~Visitor()
    {}

    void Visitor::operator()(const Bytecode& byte) const
    {
        byte.accept(*this);
    }
} // namespace bytecode
