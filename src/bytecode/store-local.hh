/// @date 19/03/2013
#ifndef STORE_LOCAL_HH
# define STORE_LOCAL_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class StoreLocal : public Bytecode
    {
        public:
            StoreLocal(const yy::location& location,
                       unsigned addr);
            virtual ~StoreLocal();

            unsigned addr_get() const;

            void accept(Visitor& visitor) const;

        protected:
            unsigned addr_;
    };
} // namespace bytecode

# include <bytecode/store-local.hxx>

#endif /* !STORE_LOCAL_HH */
