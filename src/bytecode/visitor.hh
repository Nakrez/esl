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
            virtual void operator()(const StoreLocal& byte) = 0;

            virtual void operator()(const LoadVar& byte) = 0;
            virtual void operator()(const LoadLocal& byte) = 0;
            virtual void operator()(const LoadStr& byte) = 0;
            virtual void operator()(const LoadInt& byte) = 0;
            virtual void operator()(const LoadFloat& byte) = 0;
            virtual void operator()(const LoadAttr& byte) = 0;
            virtual void operator()(const LoadModule& byte) = 0;

            virtual void operator()(const OpenModule& byte) = 0;
            virtual void operator()(const CallModule& byte) = 0;
            virtual void operator()(const CallMethod& byte) = 0;
            virtual void operator()(const CallFunction& byte) = 0;

            virtual void operator()(const StartClass& byte) = 0;
            virtual void operator()(const EndClass& byte) = 0;
            virtual void operator()(const RegisterAttribut& byte) = 0;
            virtual void operator()(const RegisterFunction& byte) = 0;
            virtual void operator()(const Inherit& byte) = 0;

            virtual void operator()(const Jump& byte) = 0;
            virtual void operator()(const JumpTrue& byte) = 0;
            virtual void operator()(const JumpFalse& byte) = 0;

            virtual void operator()(const Return& byte) = 0;

            virtual void operator()(const Delim& byte) = 0;
    };
} // namespace bytecode

#endif /* !BYTECODE_VISITOR_HH */
