#include <ast/class-dec.hh>
#include <ast/all.hh>

namespace ast
{
    ClassDec::ClassDec(const yy::location& location,
                       const misc::symbol& name,
                       IdList* inherit,
                       DecList* components)
        : Dec(location, name)
        , inherit_(inherit)
        , components_(components)
    {}

    ClassDec::~ClassDec()
    {
        delete inherit_;
        delete components_;
    }

} // namespace ast
