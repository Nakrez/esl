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

            virtual void operator()(const Bytecode& byte);

            virtual void operator()(const Pop& byte) = 0;

            virtual void operator()(const Operation& byte) = 0;
            virtual void operator()(const BracketOp& byte) = 0;
            virtual void operator()(const NewObject& byte) = 0;

            virtual void operator()(const StoreVar& byte) = 0;
            virtual void operator()(const StoreAttr& byte) = 0;
            virtual void operator()(const StoreArray& byte) = 0;

            virtual void operator()(const LoadVar& byte) = 0;
            virtual void operator()(const LoadStr& byte) = 0;
            virtual void operator()(const LoadInt& byte) = 0;
            virtual void operator()(const LoadFloat& byte) = 0;
            virtual void operator()(const LoadAttr& byte) = 0;
            virtual void operator()(const LoadModule& byte) = 0;

            virtual void operator()(const OpenModule& byte) = 0;
    };
} // namespace bytecode

#endif /* !BYTECODE_VISITOR_HH */
