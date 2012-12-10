#include "vm.hh"

esl::Vm::Vm (std::vector<esl::Bytecode*>* code)
{
    this->code_ = code;
    this->runtime_ = new esl::ExecutableContext();
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
    esl::Bytecode *instr = nullptr;

    while (this->runtime_->pc_get() < this->code_->size())
    {
        instr = this->code_->at(this->runtime_->pc_get());
        switch (instr->get_type())
        {
            case POP:
                this->stack_->pop();
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
                break;
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
    if (this->stack_->empty())
        throw esl::EmptyStackException();

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
    //delete this->runtime_;

    /* Restore the previous context */
    /* TODO: Check top of the stack is a context */
    this->runtime_ = (esl::Runtime*)(this->stack_->top()->content_get());

    this->stack_->pop();

    if (ret)
        this->stack_->push(ret);
    else
        this->stack_->push(new esl::ContentObject(O_NIL, nullptr));

}

void esl::Vm::call_function(esl::Bytecode *instr)
{
    std::string fun_name;
    std::pair<esl::Callback, int> fun;
    esl::Params* params = new esl::Params();
    esl::Runtime* fun_runtime = new esl::Runtime(*(this->runtime_));

    /* Storing all args before context switch */
    while (!(this->stack_->empty()) &&
           this->stack_->top()->type_get() != O_RUNTIME)
    {
        params->params_set((esl::Value*)this->stack_->top()->content_get());
        this->stack_->pop();
    }

    /* Push current context in the stack */
    this->stack_->push(new esl::ContentObject(O_RUNTIME, this->runtime_));

    /* TODO: Check fun_name is a string */
    fun_name = *((std::string *)(instr->get_param()->content_get()));

    /* TODO: Check that function is registerd */
    fun = this->runtime_->function_get(fun_name);

    /* Setup new context */
    if (fun.first(fun_runtime, params) == nullptr) /* std_callback */
    {
        for (int i = 0; i < params->count(); ++i)
           this->stack_->push(new esl::ContentObject(O_VALUE, params->get_params(i + 1)));

        fun_runtime->pc_set(fun.second + 1);

        this->runtime_ = fun_runtime;
    }

    /*
    ** Register the current function in the new context
    ** Use for recursive function)
    */
}

void esl::Vm::store(esl::Bytecode *instr)
{
    std::string *var_name = NULL;
    esl::Value *value = NULL;

    var_name = static_cast<std::string*>(instr->get_param()->content_get());

    /* TODO: check type of TOS */
    if (this->stack_->top()->type_get() != O_VALUE || var_name == nullptr)
        std::cout << "BUG ISSUE esl::Vm::store" << this->runtime_->pc_get() << std::endl;

    value = static_cast<esl::Value*>(this->stack_->top()->content_get());

    if (value == nullptr)
        std::cout << "BUG ISSUE2 esl::Vm::store" << std::endl;

    this->runtime_->variable_set(*var_name, value);
}

void esl::Vm::load(esl::Bytecode *instr)
{
    std::string *var_name = NULL;
    esl::Value *value = NULL;

    var_name = (std::string *)instr->get_param()->content_get();

    /* TODO: check existance */

    value = this->runtime_->variable_get(*var_name);

    this->stack_->push(new esl::ContentObject(O_VALUE, value));
}

void esl::Vm::jump(esl::Bytecode *instr)
{
    int *addr = (int *)instr->get_param()->content_get();

    this->runtime_->pc_incr(*addr);
}

void esl::Vm::register_function(esl::Bytecode *instr)
{
    std::string     *var_name = nullptr;

    var_name = (std::string *)instr->get_param()->content_get();

    /* TODO: Register Function */
    this->runtime_->function_set(*var_name,
                                 esl::std_callback,
                                 this->runtime_->pc_get());
}

void esl::Vm::print()
{
    esl::Value* value = nullptr;

    /* Print all the stack till the end or a context */
    while (!(this->stack_->empty()) &&
           this->stack_->top()->type_get() == O_VALUE)
    {
        if (this->stack_->top()->type_get() == O_NIL)
            std::cout << "nill" << std::endl;
        else
        {
            value = (esl::Value*)this->stack_->top()->content_get();
            value->print();
        }
        this->stack_->pop();
    }

    std::cout << std::endl;

    /* Push a return value */
    this->stack_->push(new esl::ContentObject(O_NIL, nullptr));
}
