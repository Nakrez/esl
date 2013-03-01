#include <ast/module-attribut-var.hh>

namespace ast
{
    ModuleAttributVar::ModuleAttributVar(const yy::location& location,
                                         Var* var,
                                         const misc::symbol& symbol)
        : Var(location)
        , var_(var)
        , name_(symbol)
    {}

    ModuleAttributVar::~ModuleAttributVar()
    {
        delete var_;
    }
} // namespace ast
