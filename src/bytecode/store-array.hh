/// @date 05/03/2013
#ifndef STORE_ARRAY_HH
# define STORE_ARRAY_HH

# include <bytecode/visitor.hh>
# include <bytecode/bytecode.hh>

namespace bytecode
{
    class StoreArray : public Bytecode
    {
        public:
            StoreArray(const yy::location& location);
            virtual ~StoreArray();

            virtual void accept(const Visitor& visitor) const;
    };
} // namespace bytecode

# include <bytecode/store-array.hxx>

#endif /* !STORE_ARRAY_HH */
