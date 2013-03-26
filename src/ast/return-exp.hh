#ifndef RETURN_EXP_HH
# define RETURN_EXP_HH

# include <ast/exp.hh>

namespace ast
{
    class ReturnExp : public Exp
    {
        public:
            ReturnExp(const yy::location& location,
                      Exp* exp);
            virtual ~ReturnExp();

            const Exp* exp_get() const;
            Exp* exp_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            Exp* exp_;
    };
} // namespace ast

# include <ast/return-exp.hxx>

#endif /* !RETURN_EXP_HH */
