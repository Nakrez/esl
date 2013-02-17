#ifndef VAR_DEC_HH
# define VAR_DEC_HH

# include <ast/dec.hh>
# include <ast/exp.hh>

namespace ast
{
    class VarDec : public Dec
    {
        public:
            VarDec(const yy::location& location,
                   const misc::symbol& name,
                   Exp* value);
            virtual ~VarDec();

            Exp* value_get() const;
            void value_set(Exp* value);

        protected:
            Exp* value_;
    };
} // namespace ast

# include <ast/var-dec.hxx>

#endif /* !VAR_DEC_HH */
