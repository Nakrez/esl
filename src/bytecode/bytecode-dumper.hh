/// @date 22/03/2013

#ifndef BYTECODE_DUMPER_HH
# define BYTECODE_DUMPER_HH

# include <ast/all.hh>

# include <bytecode/visitor.hh>
# include <bytecode/all.hh>

namespace bytecode
{
    class BytecodeDumper : public Visitor
    {
        public:
            BytecodeDumper(std::ostream& ostr,
                           const std::vector<std::string>& ro_data);
            ~BytecodeDumper();

            void dump(const std::vector<Bytecode*>& code);

            virtual void operator()(const Pop& byte);

            virtual void operator()(const Operation& byte);
            virtual void operator()(const BracketOp& byte);
            virtual void operator()(const NewObject& byte);

            virtual void operator()(const StoreVar& byte);
            virtual void operator()(const StoreAttr& byte);
            virtual void operator()(const StoreArray& byte);
            virtual void operator()(const StoreLocal& byte);

            virtual void operator()(const LoadVar& byte);
            virtual void operator()(const LoadLocal& byte);
            virtual void operator()(const LoadStr& byte);
            virtual void operator()(const LoadInt& byte);
            virtual void operator()(const LoadFloat& byte);
            virtual void operator()(const LoadAttr& byte);
            virtual void operator()(const LoadModule& byte);

            virtual void operator()(const OpenModule& byte);
            virtual void operator()(const CallModule& byte);
            virtual void operator()(const CallMethod& byte);
            virtual void operator()(const CallFunction& byte);

            virtual void operator()(const StartClass& byte);
            virtual void operator()(const EndClass& byte);
            virtual void operator()(const RegisterAttribut& byte);
            virtual void operator()(const RegisterFunction& byte);
            virtual void operator()(const Inherit& byte);

            virtual void operator()(const Jump& byte);
            virtual void operator()(const JumpTrue& byte);
            virtual void operator()(const JumpFalse& byte);

            virtual void operator()(const Return& byte);

            virtual void operator()(const Delim& byte);

        private:
            std::ostream& ostr_;
            std::vector<std::string> ro_data_;
    };
} // namespace bytecode

#endif /* !BYTECODE_DUMPER_HH */
