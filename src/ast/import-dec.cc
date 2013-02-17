#include <ast/import-dec.hh>

namespace ast
{
    ImportDec::ImportDec(const yy::location& location,
            const misc::symbol name)
        : Dec(location, name)
    {}

    ImportDec::~ImportDec()
    {}
} // namespace ast
