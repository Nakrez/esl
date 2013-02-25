/// date 17 Feb 2013
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
                min, /* - */
                tim, /* * */
                div, /* / */
                mod, /* % */
                pow, /* ^ */
                eq, /* == */
                neq, /* != */
                gt, /* > */
                ge, /* >= */
                lt, /* < */
                le, /* <= */
                and_, /* && */
                or_, /* || */
                not_ /* ! */
            };

            OpExp(const yy::location location,
                  Exp* lop,
                  OpExp::Operator op,
                  Exp* rop);
            ~OpExp();

            const Exp& lop_get() const;
            const Exp& rop_get() const;
            Exp& lop_get();
            Exp& rop_get();
            OpExp::Operator op_get() const;
            std::string str_op() const;

            virtual void accept(Visitor& visitor);

        protected:
            Exp* lop_;
            OpExp::Operator op_;
            Exp* rop_;
    };
} // namespace ast

# include <ast/op-exp.hxx>

#endif /* !OP_EXP_HH */
