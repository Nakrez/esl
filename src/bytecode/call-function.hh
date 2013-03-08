#ifndef CALL_FUNCTION_HH
# define CALL_FUNCTION_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class CallFunction : public Bytecode
    {
        public:
            CallFunction(const yy::location& location,
                         const misc::symbol& name);
            virtual ~CallFunction();

            const misc::symbol& name_get() const;

            void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/call-function.hxx>

#endif /* !CALL_FUNCTION_HH */
