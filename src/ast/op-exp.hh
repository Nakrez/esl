#ifndef OP_EXP_HH
# define OP_EXP_HH

# include <ast/exp.hh>

namespace ast
{
    class OpExp : public Exp
    {
        public:
            enum Operator
            {
                add, /* + */
            };

            OpExp(const yy::location location,
                  Exp* lop,
                  OpExp::Operator op,
                  Exp* rop);
            ~OpExp();

            const Exp& lop_get() const;
            const Exp& rop_get() const;
            OpExp::Operator op_get() const;

            virtual void accept(Visitor& visitor);

        protected:
            Exp* lop_;
            OpExp::Operator op_;
            Exp* rop_;
    };
} // namespace ast

# include <ast/op-exp.hxx>

#endif /* !OP_EXP_HH */
