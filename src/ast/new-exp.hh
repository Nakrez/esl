#ifndef NEW_EXP_HH
# define NEW_EXP_HH

# include <ast/visitor.hh>
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

            void accept(Visitor& visitor);

        protected:
            FunctionCallExp* exp_;
    };
} // namespace ast

# include <ast/new-exp.hxx>

#endif /* !NEW_EXP_HH */
