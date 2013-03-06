/// date 04/03/2013
#ifndef BYTECODE_VISITOR_HH
# define BYTECODE_VISITOR_HH

# include <bytecode/fwd.hh>

namespace bytecode
{
    class Visitor
    {
        public:
            Visitor();
            virtual ~Visitor();

            virtual void operator()(const Bytecode& byte) const;

            virtual void operator()(const Pop& byte) const = 0;

            virtual void operator()(const Operation& byte) const = 0;
            virtual void operator()(const BracketOp& byte) const = 0;
            virtual void operator()(const NewObject& byte) const = 0;

            virtual void operator()(const StoreVar& byte) const = 0;
            virtual void operator()(const StoreAttr& byte) const = 0;
            virtual void operator()(const StoreArray& byte) const = 0;

            virtual void operator()(const LoadVar& byte) const = 0;
            virtual void operator()(const LoadStr& byte) const = 0;
            virtual void operator()(const LoadInt& byte) const = 0;
            virtual void operator()(const LoadFloat& byte) const = 0;
            virtual void operator()(const LoadAttr& byte) const = 0;
            virtual void operator()(const LoadModule& byte) const = 0;

            virtual void operator()(const OpenModule& byte) const = 0;
    };
} // namespace bytecode

#endif /* !BYTECODE_VISITOR_HH */
