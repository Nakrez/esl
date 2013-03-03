#ifndef ARRAY_VAR_HH
# define ARRAY_VAR_HH

# include <ast/visitor.hh>
# include <ast/var.hh>
# include <ast/exp.hh>

namespace ast
{
    class ArrayVar : public Var
    {
        public:
            ArrayVar(const yy::location& location,
                     Var* var,
                     Exp* exp);
            virtual ~ArrayVar();

            const Var* var_get() const;
            Var* var_get();

            const Exp* exp_get() const;
            Exp* exp_get();

            void accept(Visitor& visitor);

        protected:
            Var* var_;
            Exp* exp_;
    };
} // namespace ast

# include <ast/array-var.hxx>

#endif /* !ARRAY_VAR_HH */
