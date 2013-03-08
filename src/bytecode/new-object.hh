// @date 05/03/2013
#ifndef NEW_OBJECT_HH
# define NEW_OBJECT_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class NewObject : public Bytecode
    {
        public:
            NewObject(const yy::location& location,
                      const misc::symbol& name);
            virtual ~NewObject();

            const misc::symbol& name_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/new-object.hxx>

#endif /* !NEW_OBJECT_HH */
