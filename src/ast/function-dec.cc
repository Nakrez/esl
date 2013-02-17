#include <ast/function-dec.hh>

namespace ast
{
    FunctionDec::FunctionDec(const yy::location& location,
                             const misc::symbol& name,
                             const VarDecList& args,
                             const ExpList& body)
        : Dec(location, name)
        , args_(args)
        , body_(body)
    {}

    FunctionDec::~FunctionDec()
    {}
} // namespace ast
