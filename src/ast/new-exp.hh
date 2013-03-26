#ifndef NEW_EXP_HH
# define NEW_EXP_HH

# include <ast/exp.hh>
# include <ast/function-call-exp.hh>

namespace ast
{
    class NewExp : public Exp
    {
        public:
            NewExp(const yy::location& location,
                   FunctionCallExp* exp);
            virtual ~NewExp();

            const FunctionCallExp* exp_get() const;
            FunctionCallExp* exp_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            FunctionCallExp* exp_;
    };
} // namespace ast

# include <ast/new-exp.hxx>

#endif /* !NEW_EXP_HH */
