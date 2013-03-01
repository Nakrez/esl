#include <ast/function-call-exp.hh>
#include <ast/all.hh>

namespace ast
{
    FunctionCallExp::FunctionCallExp(const yy::location& location,
                                     const misc::symbol& name,
                                     ExpList* args)
        : Exp(location)
        , name_(name)
        , args_(args)
    {}

    FunctionCallExp::~FunctionCallExp()
    {
        delete args_;
    }
} // namespace ast
