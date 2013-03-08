#ifndef CALL_METHOD_HH
# define CALL_METHOD_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class CallMethod : public Bytecode
    {
        public:
            CallMethod(const yy::location& location,
                       const misc::symbol& name);
            virtual ~CallMethod();

            const misc::symbol& name_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/call-method.hxx>

#endif /* !CALL_METHOD_HH */
