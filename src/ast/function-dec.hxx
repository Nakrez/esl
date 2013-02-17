#ifndef FUNCTION_DEC_HXX
# define FUNCTION_DEC_HXX

# include <ast/function-dec.hh>

namespace ast
{
    inline const VarDecList& FunctionDec::args_get() const
    {
        return args_;
    }

    inline const ExpList& FunctionDec::body_get() const
    {
        return body_;
    }

    inline void FunctionDec::args_set(const VarDecList& args)
    {
        args_ = args;
    }

    inline void FunctionDec::body_set(const ExpList& body)
    {
        body_ = body;
    }
} // namespace ast

#endif /* !FUNCTION_DEC_HXX */
