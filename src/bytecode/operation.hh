// @date 04/03/2013
#ifndef OPERATION_HH
# define OPERATION_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

# include <ast/op-exp.hh>

namespace bytecode
{
    class Operation : public Bytecode
    {
        public:
            Operation(const yy::location& location,
                      ast::OpExp::Operator op);
            virtual ~Operation();

            ast::OpExp::Operator op_get() const;
            const std::string& string_op() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            ast::OpExp::Operator op_;
    };
} // namespace bytecode

# include <bytecode/operation.hxx>

#endif /* !OPERATION_HH */
