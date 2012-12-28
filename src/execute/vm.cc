#include "vm.hh"

esl::Vm::Vm (const std::vector<esl::Bytecode*>& code)
    : stack_ ()
{
    this->code_ = code;
    this->runtime_ = new esl::ExecutableContext();
}

esl::Vm::~Vm()
{
    /*while (!(this->stack_.empty()))
    {
        delete this->stack_.top();
        this->stack_.pop();
    }*/

    delete this->runtime_;
}

void esl::Vm::run()
{
    esl::Bytecode *instr = nullptr;

    while (this->runtime_->pc_get() < this->code_.size())
    {
        instr = this->code_.at(this->runtime_->pc_get());
        switch (instr->get_type())
        {
            case POP:
                this->stack_.pop();
                break;
            case JUMP:
                this->jump(instr);
                continue;
            case LOAD_STR:
                this->load_str(instr);
                break;
            case LOAD_INT:
                this->load_int(instr);
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
            case JUMP_IF_TRUE:
                this->jump(instr, 1);
                continue;
            case JUMP_IF_FALSE:
                this->jump(instr, 0);
                continue;
            case ARITH_ADD:
                this->math_operation(esl::Operation::add_int,
                                     esl::Operation::add_str);
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
                this->bool_operation(esl::Operation::eq_int,
                                     esl::Operation::eq_str);
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
            case BOOL_OR:
                this->math(std::logical_or<int>());
                break;
            case BOOL_AND:
                this->math(std::logical_and<int>());
                break;
            case OPEN:
                this->setup_module(instr);
                break;
            case MODULE:
                this->module(instr);
                break;
            case CALL_MODULE:
                this->call_module(instr);
                break;
            default:
                break;
        }

        this->runtime_->pc_incr(1);
    }
}

void esl::Vm::math_operation(int_operation int_op, str_operation str_op)
{
    esl::Value* obj1 = nullptr;
    esl::Value* obj2 = nullptr;

    operation(obj1, obj2);

    if (obj1->type_get() == O_INT)
    {
        int *res = new int;

        *res = int_op((int*)obj2->content_get(), (int*)obj1->content_get());
        this->stack_.push(new esl::Value(O_INT, res));
    }
    else /* TODO: check if it is string */
    {
        std::string* res = new std::string;

        *res = str_op((std::string*)obj2->content_get(),
                      (std::string*)obj1->content_get());

        this->stack_.push(new esl::Value(O_STRING, res));
    }
}

void esl::Vm::bool_operation(int_operation int_op, str_bool_operation str_op)
{
    esl::Value* obj1 = nullptr;
    esl::Value* obj2 = nullptr;
    int *res = new int;

    operation(obj1, obj2);

    if (obj1->type_get() == O_INT)
        *res = int_op((int*)obj2->content_get(), (int*)obj1->content_get());
    else /* TODO: check if it is string */
        *res = str_op((std::string*)obj2->content_get(),
                      (std::string*)obj1->content_get());

    this->stack_.push(new esl::Value(O_INT, res));
}

void esl::Vm::operation (esl::Value*& obj1, esl::Value*& obj2)
{
    obj1 = static_cast<esl::Value*>(this->stack_.top());
    this->stack_.pop();

    obj2 = static_cast<esl::Value*>(this->stack_.top());
    this->stack_.pop();

    if (obj1 == nullptr || obj2 == nullptr ||
        obj1->type_get() != obj2->type_get())
    {
        std::cout << "Bad Operation" << std::endl;
        exit (3);
    }
}

void esl::Vm::setup_module (Bytecode* instr)
{
    esl::Module* module = nullptr;
    std::string* module_name = RoData::instance_get()->get(instr->get_param());
    std::string path = "./" + *module_name + ".eslm";

    module = new esl::Module(path);
    module->load();

    this->runtime_->module_set(*module_name, module);
}

void esl::Vm::module (Bytecode* instr)
{
    std::string* mod_name = RoData::instance_get()->get(instr->get_param());

    /* TODO FIX TYPE */
    this->stack_.push(new esl::ContentObject(O_RUNTIME,
                                             this->runtime_->module_get(*mod_name)));
}

void esl::Vm::call_module (Bytecode* instr)
{
    esl::Params* params = new esl::Params();
    esl::Module* module = nullptr;
    std::string* fun_name = RoData::instance_get()->get(instr->get_param());

    module = static_cast<esl::Module*>(this->stack_.top()->content_get());
    this->stack_.pop();

    /* Storing all args before context switch */
    while (!(this->stack_.empty()) &&
           this->stack_.top()->type_get() != O_RUNTIME)
    {
        params->params_set((esl::Value*)this->stack_.top());
        this->stack_.pop();
    }

    this->stack_.push(module->call(*fun_name, params));

    delete params;
}

void esl::Vm::load_int (Bytecode* instr)
{
    esl::Value* v = new esl::Value(O_INT, new int (instr->get_param()));

    this->stack_.push(v);
}

void esl::Vm::load_str (Bytecode* instr)
{
    esl::Value* v = new esl::Value(O_STRING, nullptr);

    v->content_set(RoData::instance_get()->get(instr->get_param()));

    this->stack_.push(v);
}

void esl::Vm::function_return()
{
    esl::ContentObject *ret = nullptr;

    if (this->stack_.top() && this->stack_.top()->type_get() == O_VALUE)
    {
        ret = this->stack_.top();
        this->stack_.pop();
    }

    delete this->runtime_;

    /* Restore the previous context */
    /* TODO: Check top of the stack is a context */
    this->runtime_ = (esl::Runtime*)(this->stack_.top()->content_get());

    this->stack_.pop();

    if (ret)
        this->stack_.push(ret);
    else
        this->stack_.push(new esl::ContentObject(O_NIL, nullptr));
}

void esl::Vm::call_function(esl::Bytecode *instr)
{
    std::string fun_name;
    std::pair<esl::Callback, int> fun;
    esl::Params* params = new esl::Params();
    esl::Runtime* fun_runtime = new esl::Runtime(*(this->runtime_));
    esl::ContentObject* container = nullptr;

    /* Storing all args before context switch */
    while (!(this->stack_.empty()) &&
           this->stack_.top()->type_get() != O_RUNTIME)
    {
        params->params_set((esl::Value*)this->stack_.top());
        this->stack_.pop();
    }

    /* Push current context in the stack */
    container = new esl::ContentObject(O_RUNTIME, this->runtime_);

    this->stack_.push(container);

    /* TODO: Check fun_name is a string */
    fun_name = *(RoData::instance_get()->get(instr->get_param()));

    /* TODO: Check that function is registerd */
    fun = this->runtime_->function_get(fun_name);

    /* Setup new context */
    if (fun.first(fun_runtime, params) == nullptr) /* std_callback */
    {
        for (int i = 0; i < params->count(); ++i)
            this->stack_.push(params->get_params(i + 1));

        fun_runtime->pc_set(fun.second + 1);

        this->runtime_ = fun_runtime;
    }

    delete params;
}

void esl::Vm::store(esl::Bytecode *instr)
{
    std::string *var_name = nullptr;
    esl::Value *value = nullptr;

    var_name = RoData::instance_get()->get(instr->get_param());

    /* TODO: check type of TOS */
    if ((this->stack_.top()->type_get() != O_INT &&
        this->stack_.top()->type_get() != O_STRING) ||
        var_name == nullptr)
    {
        std::cout << "BUG ISSUE esl::VM::Store" << std::endl;
    }

    value = static_cast<esl::Value*>(this->stack_.top());

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

    var_name = RoData::instance_get()->get(instr->get_param());

    if (var_name == nullptr)
        std::cout << " BUG esl::Vm::load" << std::endl;
    /* TODO: check existance */

    value = this->runtime_->variable_get(*var_name);

    this->stack_.push(value);
}

void esl::Vm::jump(esl::Bytecode *instr, int val)
{
    if (this->stack_.top()->type_get() == O_INT)
    {
        esl::Value* value = (esl::Value*)this->stack_.top();
        int* v = (int*)value->content_get();

        if (*v == val)
            jump(instr);
        else
            this->runtime_->pc_incr(1);

        this->stack_.pop();
    }
}

void esl::Vm::jump(esl::Bytecode *instr)
{
    this->runtime_->pc_incr(instr->get_param());
}

void esl::Vm::register_function(esl::Bytecode *instr)
{
    std::string     *var_name = nullptr;

    var_name = RoData::instance_get()->get(instr->get_param());

    /* TODO: Register Function */
    this->runtime_->function_set(*var_name,
                                 esl::std_callback,
                                 this->runtime_->pc_get());
}
