#ifndef MODULE_ATTRIBUT_VAR_HH
# define MODULE_ATTRIBUT_VAR_HH

# include <ast/var.hh>

# include <misc/symbol.hh>

namespace ast
{
    class ModuleAttributVar : public Var
    {
        public:
            ModuleAttributVar(const yy::location& location,
                              Var* var,
                              const misc::symbol& symbol);
            virtual ~ModuleAttributVar();

            const Var* var_get() const;
            Var* var_get();

            misc::symbol& name_get();
            const misc::symbol& name_get() const;

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            Var* var_;
            misc::symbol name_;
    };
} // namespace ast

# include <ast/module-attribut-var.hxx>

#endif /* !MODULE_ATTRIBUT_VAR_HH */
