// @date 05/03/2013
#ifndef STORE_VAR_HH
# define STORE_VAR_HH

# include <misc/symbol.hh>

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class StoreVar : public Bytecode
    {
        public:
            StoreVar(const yy::location& location,
                     const misc::symbol& name);
            virtual ~StoreVar();

            const misc::symbol& name_get() const;

            virtual void accept(const Visitor& visitor) const;

        protected:
            misc::symbol name_;
    };
} // namespace bytecode

# include <bytecode/store-var.hxx>

#endif /* !STORE_VAR_HH */
