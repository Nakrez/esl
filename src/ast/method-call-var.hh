#ifndef METHOD_CALL_VAR_HH
# define METHOD_CALL_VAR_HH

# include <ast/var.hh>
# include <ast/function-call-exp.hh>

# include <ast/visitor.hh>

namespace ast
{
    class MethodCallVar : public Var
    {
        public:
            MethodCallVar(const yy::location& location,
                          Var* var,
                          FunctionCallExp* call);
            virtual ~MethodCallVar();

            Var* var_get();
            const Var* var_get() const;

            const FunctionCallExp* call_get() const;
            FunctionCallExp* call_get();

            void accept(Visitor& visitor);

        protected:
            Var* var_;
            FunctionCallExp* call_;
    };
} // namespace ast

# include <ast/method-call-var.hxx>

#endif /* !METHOD_CALL_VAR_HH */
