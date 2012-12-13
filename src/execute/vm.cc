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
                this->pop();
                break;
            case JUMP:
                this->jump(instr);
                continue;
            case LOAD_CST:
                this->load_cst(instr);
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
                this->function_return();
                break;
            case PRINT:
                this->print();
                break;
            case JUMP_IF_TRUE:
                this->jump(instr, 1);
                continue;
            case JUMP_IF_FALSE:
                this->jump(instr, 0);
                continue;
            case ARITH_ADD:
                this->math(std::plus<int>());
                break;
            case ARITH_MINUS:
                this->math(std::minus<int>());
                break;
            case ARITH_MUL:
                this->math(std::multiplies<int>());
                break;
            case ARITH_DIV:
                this->math(std::divides<int>());
                break;
            case ARITH_MOD:
                this->math(std::modulus<int>());
                break;
            case BOOL_EQ:
                this->math(std::equal_to<int>());
                break;
            case BOOL_DIFF:
                this->math(std::not_equal_to<int>());
                break;
            case BOOL_GT:
                this->math(std::greater<int>());
                break;
            case BOOL_GE:
                this->math(std::greater_equal<int>());
                break;
            case BOOL_LT:
                this->math(std::less<int>());
                break;
            case BOOL_LE:
                this->math(std::less_equal<int>());
                break;
            default:
                break;
        }

        this->runtime_->pc_incr(1);
    }
}

void esl::Vm::load_cst (Bytecode* instr)
{
    esl::Value* v = new esl::Value(*((esl::Value*)(instr->get_param())));
    esl::ContentObject* obj = new esl::ContentObject(O_VALUE, v);

    this->stack_->push(obj);
}

void esl::Vm::decr_obj (void* object)
{
    if (object == nullptr)
        return;

    esl::Object* obj = nullptr;
    obj = static_cast<esl::Object*>(object);

    if (obj == nullptr)
        return;

    obj->decr_ref();
}

void esl::Vm::incr_obj (void* object)
{
    if (object == nullptr)
        return;

    esl::Object* obj = nullptr;
    obj = static_cast<esl::Object*>(object);

    if (obj == nullptr)
        return;

    obj->incr_ref();
}

void esl::Vm::pop()
{
    /* Delete TOS */
    delete this->stack_->top();

    /* Pop it */
    this->stack_->pop();
}

void esl::Vm::function_return()
{
    esl::ContentObject *ret = nullptr;

    if (this->stack_->top() && this->stack_->top()->type_get() == O_VALUE)
    {
        ret = this->stack_->top();
        this->stack_->pop();
    }

    delete this->runtime_;

    /* Restore the previous context */
    /* TODO: Check top of the stack is a context */
    this->runtime_ = (esl::Runtime*)(this->stack_->top()->content_get());

    this->pop();

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
    esl::ContentObject* container = nullptr;

    /* Storing all args before context switch */
    while (!(this->stack_->empty()) &&
           this->stack_->top()->type_get() != O_RUNTIME)
    {
        params->params_set((esl::Value*)this->stack_->top()->content_get());
        this->stack_->pop();
    }

    /* Push current context in the stack */
    container = new esl::ContentObject(O_RUNTIME, this->runtime_);

    this->stack_->push(container);

    /* TODO: Check fun_name is a string */
    fun_name = *((std::string *)(instr->get_param()->content_get()));

    /* TODO: Check that function is registerd */
    fun = this->runtime_->function_get(fun_name);

    /* Setup new context */
    if (fun.first(fun_runtime, params) == nullptr) /* std_callback */
    {
        for (int i = 0; i < params->count(); ++i)
            this->stack_->push(new esl::ContentObject(O_VALUE,
                                                      params->get_params(i + 1)));

        fun_runtime->pc_set(fun.second + 1);

        this->runtime_ = fun_runtime;
    }

    delete params;

    /*
    ** Register the current function in the new context
    ** Use for recursive function)
    */
}

void esl::Vm::store(esl::Bytecode *instr)
{
    std::string *var_name = nullptr;
    esl::Value *value = nullptr;

    var_name = static_cast<std::string*>(instr->get_param()->content_get());

    /* TODO: check type of TOS */
    if (this->stack_->top()->type_get() != O_VALUE || var_name == nullptr)
    {

    }

    value = static_cast<esl::Value*>(this->stack_->top()->content_get());

    if (value == nullptr)
    {
        std::cout << "BUG ISSUE2 esl::Vm::store" << std::endl;
    }

    this->runtime_->variable_set(*var_name, value);
}

void esl::Vm::load(esl::Bytecode *instr)
{
    std::string* var_name = nullptr;
    esl::Value* value = nullptr;
    esl::ContentObject* container = nullptr;

    var_name = (std::string *)instr->get_param()->content_get();

    /* TODO: check existance */

    value = this->runtime_->variable_get(*var_name);
    container = new esl::ContentObject(O_VALUE, value);

    this->stack_->push(container);
}

void esl::Vm::jump(esl::Bytecode *instr, int val)
{
    if (this->stack_->top()->type_get() == O_VALUE)
    {
        esl::Value* value = (esl::Value*)this->stack_->top()->content_get();
        int* v = (int*)value->content_get();

        if (*v == val)
            jump(instr);
        else
            this->runtime_->pc_incr(1);

        this->pop();
    }
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
            std::cout << "nil" << std::endl;
        else
        {
            value = (esl::Value*)this->stack_->top()->content_get();
            value->print();
        }
        this->pop();
    }

    std::cout << std::endl;

    /* Push a return value */
    this->stack_->push(new esl::ContentObject(O_NIL, nullptr));
}
