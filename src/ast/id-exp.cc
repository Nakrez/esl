#include <ast/id-exp.hh>

namespace ast
{
    IdExp::IdExp(const yy::location& location,
                 const misc::symbol& name)
        : Exp(location)
        , name_(name)
    {}

    IdExp::~IdExp()
    {}
} // namespace ast
