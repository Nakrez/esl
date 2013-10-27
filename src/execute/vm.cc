#include <execute/vm.hh>

namespace execute
{
    Vm::Vm(const Executable& exec)
        : exec_(exec)
        , error_()
        , calculus_stack_()
        , pc_ (0)
    {}

    Vm::~Vm()
    {}

    void Vm::run()
    {
        // Register ESL default types
        (new esl::Int())->init();
        (new esl::String())->init();
        (new esl::Array())->init();

        // Execute every instruction

        for ( ; pc_ < exec_.code_get().size() ; ++pc_)
        {
            exec_.code_get().at(pc_)->accept(*this);
        }
    }

    void Vm::operator()(const bytecode::Pop&)
    {

    }

    void Vm::operator()(const bytecode::Operation&)
    {

    }

    void Vm::operator()(const bytecode::BracketOp&)
    {

    }

    void Vm::operator()(const bytecode::NewObject&)
    {

    }

    void Vm::operator()(const bytecode::StoreVar&)
    {

    }

    void Vm::operator()(const bytecode::StoreAttr&)
    {

    }

    void Vm::operator()(const bytecode::StoreArray&)
    {

    }

    void Vm::operator()(const bytecode::StoreLocal&)
    {

    }

    void Vm::operator()(const bytecode::LoadVar&)
    {

    }

    void Vm::operator()(const bytecode::LoadLocal&)
    {

    }

    void Vm::operator()(const bytecode::LoadStr&)
    {

    }

    void Vm::operator()(const bytecode::LoadInt&)
    {

    }

    void Vm::operator()(const bytecode::LoadFloat&)
    {

    }

    void Vm::operator()(const bytecode::LoadAttr&)
    {

    }

    void Vm::operator()(const bytecode::LoadModule&)
    {

    }

    void Vm::operator()(const bytecode::OpenModule&)
    {

    }

    void Vm::operator()(const bytecode::CallModule&)
    {

    }

    void Vm::operator()(const bytecode::CallMethod&)
    {

    }

    void Vm::operator()(const bytecode::CallFunction&)
    {

    }

    void Vm::operator()(const bytecode::StartClass&)
    {

    }
    void Vm::operator()(const bytecode::EndClass&)
    {

    }
    void Vm::operator()(const bytecode::RegisterAttribut&)
    {

    }

    void Vm::operator()(const bytecode::RegisterFunction&)
    {

    }

    void Vm::operator()(const bytecode::Inherit&)
    {

    }

    void Vm::operator()(const bytecode::Jump&)
    {

    }
    void Vm::operator()(const bytecode::JumpTrue&)
    {

    }
    void Vm::operator()(const bytecode::JumpFalse&)
    {

    }

    void Vm::operator()(const bytecode::Return&)
    {

    }

    void Vm::operator()(const bytecode::Delim&)
    {

    }
} // namespace execute
