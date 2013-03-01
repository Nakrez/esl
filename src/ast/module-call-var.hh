#ifndef MODULE_CALL_VAR_HH
# define MODULE_CALL_VAR_HH

# include <ast/var.hh>
# include <ast/function-call-exp.hh>

# include <ast/visitor.hh>

namespace ast
{
    class ModuleCallVar : public Var
    {
        public:
            ModuleCallVar(const yy::location& location,
                          Var* var,
                          FunctionCallExp* call);
            virtual ~ModuleCallVar();

            const Var* var_get() const;
            Var* var_get();

            const FunctionCallExp* call_get() const;
            FunctionCallExp* call_get();

            void accept(Visitor& visitor);

        protected:
            Var* var_;
            FunctionCallExp* call_;
    };
} // namespace ast

# include <ast/module-call-var.hxx>

#endif /* !MODULE_CALL_VAR_HH */
