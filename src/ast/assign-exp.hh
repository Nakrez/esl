#ifndef ASSIGN_EXP_HH
# define ASSIGN_EXP_HH

# include <ast/visitor.hh>
# include <ast/exp.hh>
# include <ast/var.hh>

namespace ast
{
    class AssignExp : public Exp
    {
        public:
            AssignExp(const yy::location& location,
                      Var* var,
                      Exp* exp);
            virtual ~AssignExp();

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

# include <ast/assign-exp.hxx>

#endif /* !ASSIGN_EXP_HH */
