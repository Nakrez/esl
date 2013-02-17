/// date 17 Feb 2013
#ifndef FUNCTION_DEC_HH
# define FUNCTION_DEC_HH

# include <list>

# include <ast/dec.hh>
# include <ast/var-dec-list.hh>
# include <ast/exp-list.hh>

namespace ast
{
    class FunctionDec : public Dec
    {
        public:
            FunctionDec(const yy::location& location,
                        const misc::symbol& name,
                        const VarDecList& args,
                        const ExpList& body);
            virtual ~FunctionDec();

            const VarDecList& args_get() const;
            const ExpList& body_get() const;

            virtual void accept(Visitor& visitor);

        protected:
            VarDecList args_;
            ExpList body_;
    };
} // namespace ast

# include <ast/function-dec.hxx>

#endif /* !FUNCTION_DEC_HH */