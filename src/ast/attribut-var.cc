#include <ast/attribut-var.hh>


namespace ast
{
    AttributVar::AttributVar(const yy::location& location,
                             Var& call_var,
                             const misc::symbol& name)
        : Var(location)
        , call_var_(&call_var)
        , name_(name)
    {}

    AttributVar::~AttributVar()
    {
        delete call_var_;
    }
} // namespace ast
