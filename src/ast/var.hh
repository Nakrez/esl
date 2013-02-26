#ifndef VAR_HH
# define VAR_HH

# include <ast/ast.hh>
# include <misc/symbol.hh>

namespace ast
{
    class Var : public Ast
    {
        public:
            Var(const yy::location& location,
                    const misc::symbol& name);
            virtual ~Var();

            const misc::symbol& name_get() const;

        protected:
            misc::symbol name_;
    };
} // namespace ast

# include <ast/var.hxx>

#endif /* !VAR_HH */
