/// @date 08/03/2013
#ifndef START_CLASS_HH
# define START_CLASS_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class StartClass : public Bytecode
    {
        public:
            StartClass(const yy::location& location,
                       const misc::symbol& name);
            virtual ~StartClass();

            const misc::symbol& name_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/start-class.hxx>

#endif /* !START_CLASS_HH */
