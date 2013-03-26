#ifndef FUNCTION_DEC_HXX
# define FUNCTION_DEC_HXX

# include <ast/visitor.hh>

# include <ast/function-dec.hh>

namespace ast
{
    inline const VarDecList* FunctionDec::args_get() const
    {
        return args_;
    }

    inline const InstrList* FunctionDec::body_get() const
    {
        return body_;
    }

    inline VarDecList* FunctionDec::args_get()
    {
        return args_;
    }

    inline InstrList* FunctionDec::body_get()
    {
        return body_;
    }

    inline void FunctionDec::accept(Visitor& visitor)
    {
        visitor(*this);
    }

    inline void FunctionDec::accept(ConstVisitor& visitor) const
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !FUNCTION_DEC_HXX */
