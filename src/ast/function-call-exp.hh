/// date 01/03/2013
#ifndef FUNCTION_CALL_EXP_HH
# define FUNCTION_CALL_EXP_HH

# include <ast/fwd.hh>
# include <ast/visitor.hh>
# include <ast/exp.hh>

# include <misc/symbol.hh>

namespace ast
{
    class FunctionCallExp : public Exp
    {
        public:
            FunctionCallExp(const yy::location& location,
                            const misc::symbol& name,
                            ExpList* args);
            virtual ~FunctionCallExp();

            const misc::symbol& name_get() const;

            const ExpList* args_get() const;
            ExpList* args_get();

            void accept(Visitor& visitor);

        protected:
            misc::symbol name_;
            ExpList* args_;
    };
} // namespace ast

# include <ast/function-call-exp.hxx>

#endif /* !FUNCTION_CALL_EXP_HH */
