/// @date 08/03/2013
#ifndef REGISTER_FUNCTION_HH
# define REGISTER_FUNCTION_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class RegisterFunction : public Bytecode
    {
        public:
            RegisterFunction(const yy::location& location,
                             const misc::symbol& name);
            virtual ~RegisterFunction();

            const misc::symbol& name_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/register-function.hxx>

#endif /* !REGISTER_FUNCTION_HH */
