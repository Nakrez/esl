#include <ast/method-dec.hh>

namespace ast
{
    MethodDec::MethodDec(const yy::location& location,
                         const misc::symbol& name,
                         VarDecList* args,
                         InstrList* body,
                         misc::visibility visibility)
        : FunctionDec(location, name, args, body)
        , visibility_(visibility)
    {}

    MethodDec::~MethodDec()
    {}
} // namespace ast
