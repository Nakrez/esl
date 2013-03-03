#ifndef METHOD_DEC_HH
# define METHOD_DEC_HH

# include <ast/visitor.hh>
# include <ast/function-dec.hh>

# include <misc/visibility.hh>

namespace ast
{
    class MethodDec : public FunctionDec
    {
        public:
            MethodDec(const yy::location& location,
                      const misc::symbol& name,
                      VarDecList* args,
                      InstrList* body,
                      misc::visibility visibility);
            virtual ~MethodDec();

            misc::visibility visibility_get() const;
            void visibility_set(misc::visibility visibility);

            void accept(Visitor& visitor);
        protected:
            misc::visibility visibility_;
    };
} // namespace ast

# include <ast/method-dec.hxx>

#endif /* !METHOD_DEC_HH */
