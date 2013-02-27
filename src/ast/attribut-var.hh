#ifndef ATTRIBUT_VAR_HH
# define ATTRIBUT_VAR_HH

# include <ast/var.hh>
# include <ast/visitor.hh>

namespace ast
{
    class AttributVar : public Var
    {
        public:
            AttributVar(const yy::location& location,
                        Var& call_var,
                        const misc::symbol& name);
            virtual ~AttributVar();

            const Var& call_var_get() const;
            Var& call_var_get();

            const misc::symbol& name_get() const;

            void accept(Visitor& visitor);

        protected:
            Var* call_var_;
            misc::symbol name_;
    };
} // namespace ast

# include <ast/attribut-var.hxx>

#endif /* !ATTRIBUT_VAR_HH */
