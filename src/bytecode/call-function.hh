/// @date 08/03/2013
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
                         unsigned addr);
            virtual ~CallFunction();

            unsigned addr_get() const;

            void accept(Visitor& visitor) const;

        protected:
            unsigned addr_;
    };
} // namespace bytecode

# include <bytecode/call-function.hxx>

#endif /* !CALL_FUNCTION_HH */
