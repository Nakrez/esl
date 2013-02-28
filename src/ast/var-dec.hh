/// date 28/02/2013
#ifndef VAR_DEC_HH
# define VAR_DEC_HH

# include <ast/dec.hh>
# include <ast/visitor.hh>

namespace ast
{
    class VarDec : public Dec
    {
        public:
            VarDec(const yy::location& location,
                   const misc::symbol& name);
            VarDec(const yy::location& location,
                   const misc::symbol& name,
                   Exp* exp);
            virtual ~VarDec();

            const Exp* exp_get() const;
            Exp* exp_get();

            virtual void accept(Visitor& visitor);

        protected:
            Exp* exp_;

    };
} // namespace ast

# include <ast/var-dec.hxx>

#endif /* !VAR_DEC_HH */
