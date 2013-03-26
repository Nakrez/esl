#ifndef VAR_ID_HH
# define VAR_ID_HH

# include <ast/var.hh>

namespace ast
{
    class VarId : public Var
    {
        public:
            VarId(const yy::location& location,
                  const misc::symbol& name);
            virtual ~VarId();

            const misc::symbol& name_get() const;
            misc::symbol& name_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace ast

# include <ast/var-id.hxx>

#endif /* !VAR_ID_HH */
