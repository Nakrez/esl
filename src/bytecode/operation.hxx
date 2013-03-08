#ifndef OPERATION_HXX
# define OPERATION_HXX

# include <bytecode/operation.hh>

namespace bytecode
{
    inline ast::OpExp::Operator Operation::op_get() const
    {
        return op_;
    }

    inline void Operation::accept(Visitor& visitor) const
    {
        visitor(*this);
    }
} // namespace bytecode

#endif /* !OPERATION_HXX */
