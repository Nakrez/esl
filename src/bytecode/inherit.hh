#ifndef INHERIT_HH
# define INHERIT_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class Inherit : public Bytecode
    {
        public:
            Inherit(const yy::location& location,
                    const misc::symbol& name);
            virtual ~Inherit();

            const misc::symbol& name_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/inherit.hxx>

#endif /* !INHERIT_HH */
