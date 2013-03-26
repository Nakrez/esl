/// date 17 Feb 2013
#ifndef FUNCTION_DEC_HH
# define FUNCTION_DEC_HH

# include <list>

# include <ast/fwd.hh>
# include <ast/dec.hh>

namespace ast
{
    class FunctionDec : public Dec
    {
        public:
            FunctionDec(const yy::location& location,
                        const misc::symbol& name,
                        VarDecList* args,
                        InstrList* body);
            virtual ~FunctionDec();

            const VarDecList* args_get() const;
            const InstrList* body_get() const;

            VarDecList* args_get();
            InstrList* body_get();

            virtual void accept(Visitor& visitor);
            virtual void accept(ConstVisitor& visitor) const;

        protected:
            VarDecList* args_;
            InstrList* body_;
    };
} // namespace ast

# include <ast/function-dec.hxx>

#endif /* !FUNCTION_DEC_HH */
