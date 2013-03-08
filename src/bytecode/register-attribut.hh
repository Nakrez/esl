/// @date 08/03/2013
#ifndef REGISTER_ATTRIBUT_HH
# define REGISTER_ATTRIBUT_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class RegisterAttribut : public Bytecode
    {
        public:
            RegisterAttribut(const yy::location& location,
                             const misc::symbol& name);
            virtual ~RegisterAttribut();

            const misc::symbol& name_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/register-attribut.hxx>

#endif /* !REGISTER_ATTRIBUT_HH */
