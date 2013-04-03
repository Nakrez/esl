#include <execute/vm.hh>

namespace execute
{
    Vm::Vm(const Executable& exec)
        : exec_(exec)
        , error_()
        , calculus_stack_()
    {}

    Vm::~Vm()
    {}

    void Vm::run()
    {
        (new esl::Int())->init();
        (new esl::String())->init();
        (new esl::Array())->init();

        for (auto instr : exec_.code_get())
            instr->accept(*this);
    }

    void Vm::operator()(const bytecode::Pop& byte)
    {
        calculus_stack_.top()->decr();
        calculus_stack_.pop();
    }

    void Vm::operator()(const bytecode::Operation& byte)
    {

    }

    void Vm::operator()(const bytecode::BracketOp& byte)
    {

    }

    void Vm::operator()(const bytecode::NewObject& byte)
    {

    }

    void Vm::operator()(const bytecode::StoreVar& byte)
    {

    }

    void Vm::operator()(const bytecode::StoreAttr& byte)
    {

    }

    void Vm::operator()(const bytecode::StoreArray& byte)
    {

    }

    void Vm::operator()(const bytecode::StoreLocal& byte)
    {

    }

    void Vm::operator()(const bytecode::LoadVar& byte)
    {

    }

    void Vm::operator()(const bytecode::LoadLocal& byte)
    {

    }

    void Vm::operator()(const bytecode::LoadStr& byte)
    {

    }

    void Vm::operator()(const bytecode::LoadInt& byte)
    {
        esl::GCObject* obj = nullptr;

        obj = new esl::GCObject(new esl::IntObject(byte.value_get()));

        calculus_stack_.push(obj);
    }

    void Vm::operator()(const bytecode::LoadFloat& byte)
    {

    }

    void Vm::operator()(const bytecode::LoadAttr& byte)
    {

    }

    void Vm::operator()(const bytecode::LoadModule& byte)
    {

    }

    void Vm::operator()(const bytecode::OpenModule& byte)
    {

    }

    void Vm::operator()(const bytecode::CallModule& byte)
    {

    }

    void Vm::operator()(const bytecode::CallMethod& byte)
    {

    }

    void Vm::operator()(const bytecode::CallFunction& byte)
    {

    }

    void Vm::operator()(const bytecode::StartClass& byte)
    {

    }
    void Vm::operator()(const bytecode::EndClass& byte)
    {

    }
    void Vm::operator()(const bytecode::RegisterAttribut& byte)
    {

    }

    void Vm::operator()(const bytecode::RegisterFunction& byte)
    {

    }

    void Vm::operator()(const bytecode::Inherit& byte)
    {

    }

    void Vm::operator()(const bytecode::Jump& byte)
    {

    }
    void Vm::operator()(const bytecode::JumpTrue& byte)
    {

    }
    void Vm::operator()(const bytecode::JumpFalse& byte)
    {

    }

    void Vm::operator()(const bytecode::Return& byte)
    {

    }

    void Vm::operator()(const bytecode::Delim& byte)
    {

    }
} // namespace execute
