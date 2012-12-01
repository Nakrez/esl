#include <execute/esl_vm.hh>

esl_vm::esl_vm(std::vector<esl_bytecode *> *code)
{
    this->code = code;
    this->current_context = new esl_context;
    this->stack = new std::stack<esl_stack_obj *>;
}

esl_vm::~esl_vm()
{
    while (!(stack->empty()))
    {
        delete stack->top();
        stack->pop();
    }

    delete stack;
    delete current_context;
}

void esl_vm::run()
{
    esl_bytecode    *instr = NULL;

    while (current_context->get_pc() < code->size())
    {
        instr = code->at(current_context->get_pc());
        switch (instr->get_type())
        {
            case POP:
                this->pop();
                break;
            case JUMP:
                this->jump(instr);
                continue;
            case LOAD_CST:
                stack->push(new esl_stack_obj(S_VAL, instr->get_param()));
                break;
            case LOAD:
                this->load(instr);
                break;
            case STORE:
                this->store(instr);
                break;
            case MAKE_FUNCTION:
                this->register_function(instr);
                break;
            case PRINT:
                this->print();
                break;
            default:
                break;
        }

        current_context->incr_pc(1);
    }
}

void esl_vm::pop()
{
    delete this->stack->top();
    this->stack->pop();
}

void esl_vm::store(esl_bytecode *instr)
{
    std::string     *var_name = NULL;
    esl_value       *value = NULL;

    var_name = (std::string *)instr->get_param()->get_value();

    /* TODO: check type of TOS */
    value = (esl_value *)this->stack->top()->get_object();

    this->current_context->set_variable(*var_name, value);
}

void esl_vm::load(esl_bytecode *instr)
{
    std::string     *var_name = NULL;
    esl_value       *value = NULL;

    var_name = (std::string *)instr->get_param()->get_value();

    value = this->current_context->get_variable(*var_name);

    stack->push(new esl_stack_obj(S_VAL, value));
}

void esl_vm::jump(esl_bytecode *instr)
{
    int *addr = (int *)instr->get_param()->get_value();

    this->current_context->incr_pc(*addr);
}

void esl_vm::register_function(esl_bytecode *instr)
{
    std::string     *var_name = NULL;

    var_name = (std::string *)instr->get_param()->get_value();

    this->current_context->set_function(*var_name,
                                        this->current_context->get_pc() + 2);
}

void esl_vm::print()
{
    esl_value   *value = NULL;

    /* Print all the stack till the end or a context */
    while (!(stack->empty()) && stack->top()->get_type() == S_VAL)
    {
        value = (esl_value *)stack->top()->get_object();
        value->print();
        this->pop();
    }

    std::cout << std::endl;

    /* Push a return value */
    stack->push(new esl_stack_obj(S_VAL, new esl_value(V_INT, new int(0))));
}
