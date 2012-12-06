#include "vm.hh"

esl::Vm::Vm (std::vector<esl::Bytecode*>* code)
{
    this->code_ = code;
    this->runtime_ = new esl::ExecutableContext;
    this->stack_ = new std::stack<esl::ContentObject*>;
}

esl::Vm::~Vm()
{
    while (!(this->stack_->empty()))
    {
        delete this->stack_->top();
        this->stack_->pop();
    }

    delete this->stack_;
    delete this->runtime_;
}

void esl::Vm::run()
{
    esl::Bytecode *instr = NULL;

    while (this->runtime_->pc_get() < this->code_->size())
    {
        instr = this->code_->at(this->runtime_->pc_get());
        switch (instr->get_type())
        {
            case POP:
                this->pop();
                break;
            case JUMP:
                this->jump(instr);
                continue;
            case LOAD_CST:
                this->stack_->push(new esl::ContentObject(O_VALUE,
                                                          instr->get_param()));
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
            case CALL_FUNCTION:
                this->call_function(instr);
                continue;
            case RETURN:
                this->function_return(instr);
                break;
            case PRINT:
                this->print();
                break;
            default:
                break;
        }

        this->runtime_->pc_incr(1);
    }
}

void esl::Vm::pop()
{
    /* Delete TOS */
    delete this->stack_->top();

    /* Pop it */
    this->stack_->pop();
}

void esl::Vm::function_return(esl::Bytecode *instr)
{
    esl::ContentObject *ret = NULL;

    if (this->stack_->top() && this->stack_->top()->type_get() == O_VALUE)
    {
        ret = this->stack_->top();
        this->stack_->pop();
    }

    /* Delete the function context */
    delete this->runtime_;

    /* Restore the previous context */
    /* TODO: Check top of the stack is a context */
    this->runtime_ = (esl::Runtime*) (this->stack_->top()->content_get());

    this->pop();

    if (instr->get_param() && instr->get_param()->type_get() != O_NIL)
    {
        /* Push the return value */
        this->stack_->push(new esl::ContentObject(O_VALUE, instr->get_param()));
    }

    if (ret)
        this->stack_->push(ret);
}

void esl::Vm::call_function(esl::Bytecode *instr)
{
    std::stack<esl::ContentObject*> tmp_stack = std::stack<esl::ContentObject *>();
    std::string fun_name;
    int fun_addr = 0;


    /* Storing all args before context switch */
    while (!(this->stack_->empty()) &&
           this->stack_->top()->type_get() != O_RUNTIME)
    {
        tmp_stack.push(this->stack_->top());
        this->stack_->pop();
    }

    /* Push current context in the stack */
    this->stack_->push(new esl::ContentObject(O_RUNTIME, this->runtime_));

    /* Put back args on the stack */
    while (!(tmp_stack.empty()))
    {
        this->stack_->push(tmp_stack.top());
        tmp_stack.pop();
    }

    /* TODO: Check fun_name is a string */
    fun_name = *((std::string *)(instr->get_param()->content_get()));

    /* TODO: Check that function is registerd */
    fun_addr = this->runtime_->get_function(fun_name);

    /* Setup new context */
    this->current_context = this->current_context->duplicate();

    /*
    ** Register the current function in the new context
    ** Use for recursive function)
    */
    this->current_context->set_function(std::string(fun_name), fun_addr);

    /* Jump top the functions code */
    this->current_context->set_pc(fun_addr);
}

void esl::Vm::store(esl_bytecode *instr)
{
    std::string     *var_name = NULL;
    esl_value       *value = NULL;

    var_name = (std::string *)instr->get_param()->get_value();

    /* TODO: check type of TOS */
    value = (esl_value *)this->stack->top()->get_object();

    this->current_context->set_variable(*var_name, value);
}

void esl::Vm::load(esl_bytecode *instr)
{
    std::string     *var_name = NULL;
    esl_value       *value = NULL;

    var_name = (std::string *)instr->get_param()->get_value();

    /* TODO: check existance */
    value = this->current_context->get_variable(*var_name);

    stack->push(new esl::ContentObject(S_VAL, value));
}

void esl::Vm::jump(esl_bytecode *instr)
{
    int *addr = (int *)instr->get_param()->get_value();

    this->current_context->incr_pc(*addr);
}

void esl::Vm::register_function(esl_bytecode *instr)
{
    std::string     *var_name = NULL;

    var_name = (std::string *)instr->get_param()->get_value();

    this->current_context->set_function(*var_name,
                                        this->current_context->get_pc() + 2);
}

void esl::Vm::print()
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
    stack->push(new esl::ContentObject(S_VAL, new esl_value(V_INT, new int(0))));
}
