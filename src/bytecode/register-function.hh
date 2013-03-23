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
                             unsigned data);
            virtual ~RegisterFunction();

            unsigned data_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            unsigned data_;
    };
} // namespace bytecode

# include <bytecode/register-function.hxx>

#endif /* !REGISTER_FUNCTION_HH */
