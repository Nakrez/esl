#include <ast/function-dec.hh>
#include <ast/all.hh>

namespace ast
{
    FunctionDec::FunctionDec(const yy::location& location,
                             const misc::symbol& name,
                             VarDecList* args,
                             InstrList* body)
        : Dec(location, name)
        , args_(args)
        , body_(body)
    {}

    FunctionDec::~FunctionDec()
    {
        delete args_;
        delete body_;
    }
} // namespace ast
