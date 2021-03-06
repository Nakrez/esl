/// @file src/execute/vm.hh
/// @brief The virtual machine that execute the ESL bytecode
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 01 Dec 2012

#ifndef VM_HH
# define VM_HH

# include <stack>

# include <misc/error.hh>

# include <type/built-in.hh>

# include <bytecode/visitor.hh>

# include <execute/executable.hh>

namespace execute
{
    class Vm : public bytecode::Visitor
    {
        public:
            Vm(const Executable& exec);
            virtual ~Vm();

            void run();
            const misc::Error& error_get() const;

            virtual void operator()(const bytecode::Pop& byte);

            virtual void operator()(const bytecode::Operation& byte);
            virtual void operator()(const bytecode::BracketOp& byte);
            virtual void operator()(const bytecode::NewObject& byte);

            virtual void operator()(const bytecode::StoreVar& byte);
            virtual void operator()(const bytecode::StoreAttr& byte);
            virtual void operator()(const bytecode::StoreArray& byte);
            virtual void operator()(const bytecode::StoreLocal& byte);

            virtual void operator()(const bytecode::LoadVar& byte);
            virtual void operator()(const bytecode::LoadLocal& byte);
            virtual void operator()(const bytecode::LoadStr& byte);
            virtual void operator()(const bytecode::LoadInt& byte);
            virtual void operator()(const bytecode::LoadFloat& byte);
            virtual void operator()(const bytecode::LoadAttr& byte);
            virtual void operator()(const bytecode::LoadModule& byte);

            virtual void operator()(const bytecode::OpenModule& byte);
            virtual void operator()(const bytecode::CallModule& byte);
            virtual void operator()(const bytecode::CallMethod& byte);
            virtual void operator()(const bytecode::CallFunction& byte);

            virtual void operator()(const bytecode::StartClass& byte);
            virtual void operator()(const bytecode::EndClass& byte);
            virtual void operator()(const bytecode::RegisterAttribut& byte);
            virtual void operator()(const bytecode::RegisterFunction& byte);
            virtual void operator()(const bytecode::Inherit& byte);

            virtual void operator()(const bytecode::Jump& byte);
            virtual void operator()(const bytecode::JumpTrue& byte);
            virtual void operator()(const bytecode::JumpFalse& byte);

            virtual void operator()(const bytecode::Return& byte);

            virtual void operator()(const bytecode::Delim& byte);

        private:
            // The executable executed
            Executable exec_;

            // Error return by the VM
            misc::Error error_;

            std::stack<std::shared_ptr<esl::Content>> calculus_stack_;

            unsigned pc_;
    };
} // namespace execute

# include <execute/vm.hxx>

#endif /* !VM_HH */
