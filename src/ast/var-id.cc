#include <ast/var-id.hh>

namespace ast
{
    VarId::VarId(const yy::location& location,
                 const misc::symbol& name)
        : Var(location)
        , name_(name)
    {}

    VarId::~VarId()
    {}
} // namespace ast
