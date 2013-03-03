#include <ast/attribut-dec.hh>

namespace ast
{
    AttributDec::AttributDec(const yy::location& location,
                             const misc::symbol& name,
                             Exp* value,
                             misc::visibility visibility)
        : Dec(location, name)
        , value_(value)
        , visibility_(visibility)
    {}

    AttributDec::~AttributDec()
    {
        delete value_;
    }
} // namespace ast
