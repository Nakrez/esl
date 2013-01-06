#include "vm.hh"
#include "../../lib/function.hh"

const std::string esl::Vm::path_lib_[] =
{
    "/usr/lib/esl/",
    "/usr/openwin/lib/esl/",
    "/usr/dt/lib/esl/",
    "/usr/4lib/esl/",
    "/usr/ucblib/esl/",
    "/usr/local/lib/esl/",
    "./"
};

esl::Vm::Vm (const std::vector<esl::Bytecode*>& code)
    : stack_ ()
{
    this->code_ = code;
    this->runtime_ = new esl::Context();
    this->runtime_->type_set("Array", esl::Array::instanciate);
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
                pop();
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
            case OP_BRACKET:
                this->operation("operator[]");
                break;
            case STORE:
                this->store(instr);
                break;
            case STORE_STK:
                this->store_stk();
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
            case OP_ADD:
                this->operation("operator+");
                break;
            case OP_MINUS:
                this->operation("operator-");
                break;
            case OP_MUL:
                this->operation("operator*");
                break;
            case OP_DIV:
                this->operation("operator/");
                break;
            case OP_MOD:
                this->operation("operator%");
                break;
            case OP_EQ:
                this->operation("operator==");
                break;
            case OP_DIFF:
                this->operation("operator!=");
                break;
            case OP_GT:
                this->operation("operator>");
                break;
            case OP_GE:
                this->operation("operator>=");
                break;
            case OP_LT:
                this->operation("operator<");
                break;
            case OP_LE:
                this->operation("operator<=");
                break;
            case OP_OR:
                this->operation("operator||");
                break;
            case OP_AND:
                this->operation("operator&&");
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
            case CALL_METHOD:
                this->call_method(instr);
                break;
            case DELIM:
                this->add_delim();
                break;
            default:
                break;
        }

        this->runtime_->pc_incr(1);
    }
}

void esl::Vm::call_method(esl::Bytecode *instr)
{
    std::string fun_name;
    esl::MemoryObject<esl::Content>* object_container = nullptr;
    esl::MemoryObject<esl::Content>* ret_value = nullptr;
    esl::Type* object = nullptr;
    esl::Context* fun_runtime = new esl::Context(*(this->runtime_));
    esl::Params params;

    /* Storing all args before context switch */
    while (!dynamic_cast<esl::StackDelimiter*>(this->stack_.top()->data_get()))
    {
        params.params_set(this->stack_.top());
        this->stack_.pop();
    }

    this->pop();

    object_container = this->stack_.top();
    object = dynamic_cast<esl::Type*> (object_container->data_get());
    this->stack_.pop();

    if (object == nullptr)
        throw esl::Exception("Method call on non object value");

    /* TODO: Check fun_name is a string */
    fun_name = *(RoData::instance_get()->get(instr->get_param()));

    /* Setup new context */
    if ((ret_value = object->call_method(fun_name, fun_runtime, params)) == nullptr)
    {
        for (int i = params.count() - 1; i >= 0; --i)
            this->stack_.push(params.get_params(i + 1));

        /* Push current context in the stack */
        this->stack_.push(new esl::MemoryObject<esl::Content>(this->runtime_));
        this->runtime_ = fun_runtime;
    }
    else /* API call */
    {
        delete fun_runtime;
        this->stack_.push(ret_value);
    }

    object_container->decr();
}

void esl::Vm::operation (const std::string& name)
{
    esl::MemoryObject<esl::Content>* obj1 = nullptr;
    esl::MemoryObject<esl::Content>* obj2 = nullptr;

    obj1 = this->stack_.top();
    this->stack_.pop();

    obj2 = this->stack_.top();
    this->stack_.pop();

    esl::Type* value1 = dynamic_cast<esl::Type*> (obj1->data_get());
    esl::Type* value2 = dynamic_cast<esl::Type*> (obj2->data_get());

    if (value1 && value2)
    {
        esl::Params params;

        params.params_set(obj1);
        params.params_set(obj2);

        esl::Context* fun_context = new esl::Context();
        esl::MemoryObject<esl::Content>* ret_value = nullptr;

        if ((ret_value = value2->call_method(name, fun_context, params)) == nullptr)
        {
            /* TODO: operator override with ESL code */
        }
        else
        {
            delete fun_context;
            this->stack_.push(ret_value);
        }
    }
    else
        throw esl::Exception("ESL is not able yet to handle different type operations");

    obj1->decr();
    obj2->decr();
}

void esl::Vm::add_delim ()
{
    esl::StackDelimiter* delim = new esl::StackDelimiter();
    this->stack_.push(new esl::MemoryObject<esl::Content>(delim));
}

void esl::Vm::pop()
{
    this->stack_.top()->decr();
    this->stack_.pop();
}

void esl::Vm::store_stk ()
{
    esl::MemoryObject<esl::Content>* tos = nullptr;
    esl::MemoryObject<esl::Content>* tos1 = nullptr;

    tos = this->stack_.top();
    this->stack_.pop();

    tos1 = this->stack_.top();
    this->stack_.pop();

    delete tos->data_get();
    tos->data_set(tos1->data_get());

    tos1->free();

    this->stack_.push(tos);
}

std::string esl::Vm::module_path(const std::string& mod_name)
{
    for (int i = 0; i < 7; ++i)
    {
        std::string path_file(path_lib_[i] + mod_name + ".eslm");
        std::ifstream exist(path_file);

        if (exist)
            return path_file;
    }

    return "";
}

void esl::Vm::setup_module (Bytecode* instr)
{
    esl::Module* module = nullptr;
    std::string* module_name = RoData::instance_get()->get(instr->get_param());

    std::string path = module_path(*module_name);

    if (path == "")
        throw Exception ("Module " + *module_name + " not found");

    module = new esl::Module(path);
    module->load();

    this->runtime_->module_set(*module_name, new esl::MemoryObject<esl::Content>(module));
}

void esl::Vm::module (Bytecode* instr)
{
    std::string* mod_name = RoData::instance_get()->get(instr->get_param());

    /* TODO FIX TYPE */
    this->stack_.push(this->runtime_->module_get(*mod_name));
}

void esl::Vm::call_module (Bytecode* instr)
{
    esl::Params params;
    esl::Module* module = nullptr;
    std::string* fun_name = RoData::instance_get()->get(instr->get_param());

    module = dynamic_cast<esl::Module*>(this->stack_.top()->data_get());
    this->stack_.pop();

    /* Storing all args before context switch */
    while (!dynamic_cast<esl::StackDelimiter*> (this->stack_.top()->data_get()))
    {
        params.params_set(this->stack_.top());
        this->stack_.pop();
    }

    this->pop();

    this->stack_.push(module->call(*fun_name, params));

    params.decr();
}

void esl::Vm::load_int (Bytecode* instr)
{
    esl::Int* v = new esl::Int(instr->get_param());

    this->stack_.push(new esl::MemoryObject<esl::Content>(v));
}

void esl::Vm::load_str (Bytecode* instr)
{
    esl::String* v = nullptr;
    std::string str = *(RoData::instance_get()->get(instr->get_param()));

    v = new esl::String(str);

    this->stack_.push(new esl::MemoryObject<esl::Content>(v));
}

void esl::Vm::function_return()
{
    std::stack<esl::MemoryObject<esl::Content>*> ret;

    while (this->stack_.top() &&
           !dynamic_cast<esl::Context*> (this->stack_.top()->data_get()))
    {
        ret.push(this->stack_.top());
        this->stack_.pop();
    }

    delete this->runtime_;

    /* Restore the previous context */
    /* TODO: Check top of the stack is a context */
    this->runtime_ = dynamic_cast<esl::Context*> (this->stack_.top()->data_get());

    if (this->runtime_ == nullptr)
        throw Exception("Internal error : null runtime");

    this->stack_.top()->free();
    this->stack_.pop();

    if (!ret.empty())
    {
        while (!ret.empty())
        {
            this->stack_.push(ret.top());
            ret.pop();
        }
    }
    else
        this->stack_.push(new MemoryObject<esl::Content>(new esl::Int(0)));
}

void esl::Vm::call_function(esl::Bytecode *instr)
{
    std::string fun_name;
    esl::Function* fun;
    esl::Params params;
    esl::Context* fun_runtime = new esl::Context(*(this->runtime_));

    /* Storing all args before context switch */
    while (!dynamic_cast<esl::StackDelimiter*>(this->stack_.top()->data_get()))
    {
        params.params_set(this->stack_.top());
        this->stack_.pop();
    }

    this->pop();

    /* Push current context in the stack */
    this->stack_.push(new esl::MemoryObject<esl::Content>(this->runtime_));

    /* TODO: Check fun_name is a string */
    fun_name = *(RoData::instance_get()->get(instr->get_param()));

    /* TODO: Check that function is registerd */
    fun = dynamic_cast<esl::Function*>(runtime_->function_get(fun_name)->data_get());

    /* Setup new context */
    if (fun->call(fun_runtime, params) == nullptr)
    {
        for (int i = params.count() - 1; i >= 0; --i)
            this->stack_.push(params.get_params(i + 1));

        this->runtime_ = fun_runtime;
    }
}

void esl::Vm::store(esl::Bytecode *instr)
{
    std::string *var_name = nullptr;

    var_name = RoData::instance_get()->get(instr->get_param());

    /* TODO: check type of TOS */
    if (!dynamic_cast<esl::Context*> (this->stack_.top()->data_get()) &&
        var_name == nullptr)
    {
        std::cout << "BUG ISSUE esl::VM::Store" << std::endl;
    }

    this->runtime_->variable_set(*var_name, this->stack_.top());
}

void esl::Vm::load(esl::Bytecode *instr)
{
    std::string* var_name = nullptr;
    esl::MemoryObject<esl::Content>* value = nullptr;

    var_name = RoData::instance_get()->get(instr->get_param());

    if (var_name == nullptr)
        std::cout << " BUG esl::Vm::load" << std::endl;
    /* TODO: check existance */

    value = this->runtime_->variable_get(*var_name);
    value->incr();

    this->stack_.push(value);
}

void esl::Vm::jump(esl::Bytecode *instr, int val)
{
    if (dynamic_cast<esl::Int*> (this->stack_.top()->data_get()))
    {
        esl::Int* value = dynamic_cast<esl::Int*> (this->stack_.top()->data_get());
        int v = value->data_get();

        if (v == val)
            jump(instr);
        else
            this->runtime_->pc_incr(1);

        this->pop();
    }
    else
        throw Exception("Conditional jump exception ! Is this a boolean expression ?");
}

void esl::Vm::jump(esl::Bytecode *instr)
{
    this->runtime_->pc_incr(instr->get_param());
}

void esl::Vm::register_function(esl::Bytecode *instr)
{
    std::string* fun_name = nullptr;
    esl::Function* fun = nullptr;

    fun_name = RoData::instance_get()->get(instr->get_param());

    fun = new esl::Function(this->runtime_->pc_get());

    /* TODO: Register Function */
    this->runtime_->function_set(*fun_name, new esl::MemoryObject<esl::Content>(fun));
}
