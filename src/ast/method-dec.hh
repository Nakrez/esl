#ifndef METHOD_DEC_HH
# define METHOD_DEC_HH

# include <ast/function-dec.hh>

# include <misc/visibility.hh>

namespace ast
{
    class MethodDec : public FunctionDec
    {
        public:
            MethodDec(const yy::location& location,
                      const misc::symbol& name,
                      const VarDecList& args,
                      InstrList* body,
                      misc::visibility visibility);
            virtual ~MethodDec();

            misc::visibility visibility_get() const;
            void visibility_set(misc::visibility visibility);

        protected:
            misc::visibility visibility_;
    };
} // namespace ast

#endif /* !METHOD_DEC_HH */
