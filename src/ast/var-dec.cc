#include <ast/var-dec.hh>

namespace ast
{
    VarDec::VarDec(const yy::location& location,
                   const misc::symbol& name)
        : Dec(location, name)
        , exp_(nullptr)
    {}

    VarDec::VarDec(const yy::location& location,
                   const misc::symbol& name,
                   Exp* exp)
        : Dec(location, name)
        , exp_(exp)
    {}

    VarDec::~VarDec()
    {
        delete exp_;
    }
} // namespace ast
