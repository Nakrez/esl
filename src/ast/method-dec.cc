#include <ast/method-dec.hh>

namespace ast
{
    MethodDec::MethodDec(const yy::location& location,
                         const misc::symbol& name,
                         const VarDecList& args,
                         const ExpList& body,
                         misc::visibility visibility)
        : FunctionDec(location, name, args, body)
        , visibility_(visibility)
    {}

    MethodDec::~MethodDec()
    {}
} // namespace ast
