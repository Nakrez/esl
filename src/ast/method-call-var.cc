#include <ast/method-call-var.hh>

namespace ast
{
    MethodCallVar::MethodCallVar(const yy::location& location,
                                 Var* var,
                                 FunctionCallExp* call)
        : Var(location)
        , var_(var)
        , call_(call)
    {}

    MethodCallVar::~MethodCallVar()
    {
        delete var_;
        delete call_;
    }
} // namespace ast
