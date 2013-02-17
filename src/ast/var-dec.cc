#include <ast/var-dec.hh>

namespace ast
{
    VarDec::VarDec(const yy::location& location,
                   const misc::symbol& name,
                   Exp* value)
        : Dec(location, name)
        , value_(value)
    {}

    VarDec::~VarDec()
    {
        if (value_)
            delete value_;
    }
} // namespace ast
