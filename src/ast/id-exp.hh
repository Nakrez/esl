#ifndef ID_EXP_HH
# define ID_EXP_HH

# include <ast/exp.hh>

# include <misc/symbol.hh>

namespace ast
{
    class IdExp : public Exp
    {
        public:
            IdExp(const yy::location& location,
                  const misc::symbol& name);
            virtual ~IdExp();

            virtual void accept(Visitor& visitor);

            const misc::symbol& name_get() const;

        protected:
            misc::symbol name_;
    };
} // namespace ast

# include <ast/id-exp.hxx>

#endif /* !ID_EXP_HH */
