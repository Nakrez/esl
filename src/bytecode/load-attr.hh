/// @date 06/03/2013
#ifndef LOAD_ATTR_HH
# define LOAD_ATTR_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class LoadAttr : public Bytecode
    {
        public:
            LoadAttr(const yy::location& location,
                     const misc::symbol& name);
            virtual ~LoadAttr();

            const misc::symbol& name_get() const;

            virtual void accept(const Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/load-attr.hxx>

#endif /* !LOAD_ATTR_HH */
