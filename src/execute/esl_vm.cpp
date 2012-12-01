#include <execute/esl_vm.hh>

esl_vm::esl_vm(std::vector<esl_bytecode *> *code)
{
    this->code = code;
    this->current_context = new esl_context;
    this->stack = new std::stack<esl_stack_obj *>;
}

esl_vm::~esl_vm()
{
    delete stack;
    delete current_context;
}

void esl_vm::run()
{
    while (current_context->get_pc() < code->size())
    {
        switch (code->at(current_context->get_pc())->get_type())
        {
            case POP:
                delete stack->top();
                stack->pop();
            default:
                break;
        }

        current_context->incr_pc();
    }
}
