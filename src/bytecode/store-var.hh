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
                     int data);
            virtual ~StoreVar();

            int data_get() const;

            virtual void accept(Visitor& visitor) const;

        protected:
            int data_;
    };
} // namespace bytecode

# include <bytecode/store-var.hxx>

#endif /* !STORE_VAR_HH */
