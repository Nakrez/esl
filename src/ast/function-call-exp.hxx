#ifndef FUNCTION_CALL_EXP_HXX
# define FUNCTION_CALL_EXP_HXX

# include <ast/function-call-exp.hh>

namespace ast
{
    inline const misc::symbol& FunctionCallExp::name_get() const
    {
        return name_;
    }

    inline const ExpList* FunctionCallExp::args_get() const
    {
        return args_;
    }

    inline ExpList* FunctionCallExp::args_get()
    {
        return args_;
    }

    inline void FunctionCallExp::accept(Visitor& visitor)
    {
        visitor(*this);
    }

} // namespace ast

#endif /* !FUNCTION_CALL_EXP_HXX */
