#ifndef STORE_ATTR_HH
# define STORE_ATTR_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class StoreAttr : public Bytecode
    {
        public:
            StoreAttr(const yy::location& location,
                      const misc::symbol& name);
            virtual ~StoreAttr();

            const misc::symbol& name_get() const;

            void accept(const Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/store-attr.hxx>

#endif /* !STORE_ATTR_HH */
