#include <ast/attribut-dec.hh>

namespace ast
{
    AttributDec::AttributDec(const yy::location& location,
                             const misc::symbol& name,
                             Exp* value,
                             misc::visibility visibility)
        : VarDec(location, name, value)
        , visibility_(visibility)
    {}

    AttributDec::~AttributDec()
    {}
} // namespace ast
