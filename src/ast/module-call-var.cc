#include <ast/module-call-var.hh>

namespace ast
{
    ModuleCallVar::ModuleCallVar(const yy::location& location,
                                 Var* var,
                                 FunctionCallExp* call)
        : Var(location)
        , var_(var)
        , call_(call)
    {}

    ModuleCallVar::~ModuleCallVar()
    {
        delete var_;
        delete call_;
    }
} // namespace ast
