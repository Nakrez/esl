#include "vm.hh"
#include "../../lib/function.hh"

esl::Vm* esl::Vm::instance_ = nullptr;

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

void esl::Vm::instanciate (const std::vector<esl::Bytecode*>& code)
{
    instance_ = new esl::Vm(code);
}

esl::Vm* esl::Vm::get ()
{
    if (!instance_)
        throw esl::Exception("Internal error : VM null");

    return instance_;
}

void esl::Vm::free ()
{
    if (instance_)
    {
        delete instance_;
        instance_ = nullptr;
    }
}

esl::Vm::Vm (const std::vector<esl::Bytecode*>& code)
    : stack_ ()
{
    this->code_ = code;
    this->runtime_ = new esl::Context();

    declaration = nullptr;

    // Register built-in types
    (new esl::Int())->init();
    (new esl::String())->init();
    (new esl::Array())->init();
}

esl::Vm::~Vm()
{
    /*while (!(this->stack_.empty()))
    {
        delete this->stack_.top();
        this->stack_.pop();
    }*/

    /*if (!this->stack_.empty())
        std::cout << "Stack not empty" << std::endl;
    */
    delete this->runtime_;
}

void esl::Vm::run()
{
    esl::Bytecode *instr = nullptr;

    // While PC is pointing on an instruction
    while (this->runtime_->pc_get() < this->code_.size())
    {
        // Call the right function to execute the current instruction
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
            case OP_POW:
                this->operation("operator^");
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
            case OP_NEW:
                this->instanciation(instr);
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
            case START_CLASS:
                this->create_type(instr);
                break;
            case END_CLASS:
                declaration = nullptr;
                break;
            case MAKE_ATTRIBUT:
                this->make_attribut(instr);
                break;
            case STORE_ATTR:
                store_attribut(instr);
                break;
            case LOAD_ATTR:
                load_attribut(instr);
                break;
            case DELIM:
                this->add_delim();
                break;
            case INHERIT:
                this->inherit(instr);
                break;
            default:
                break;
        }

        this->runtime_->pc_incr(1);
    }
}

bool esl::Vm::is_register_function(const std::string& name) const
{
    return runtime_->function_exist(name);
}

void esl::Vm::inherit (Bytecode* instr)
{
    // Exctract the mother name
    std::string name = *(RoData::instance_get()->get(instr->get_param()));

    // Check if there is a class that is in declaration
    if (!declaration)
        throw esl::Exception("Internal error no declaration found");

    // Register the inheritance
    declaration->inherit(name);
}

void esl::Vm::store_attribut (Bytecode* instr)
{
    esl::GCObject* content = stack_.top();
    esl::Object* object = dynamic_cast<esl::Object*>(content->data_get());
    std::string attr_name = *(RoData::instance_get()->get(instr->get_param()));

    this->stack_.pop();

    this->stack_.top()->incr();
    object->update_attribut (attr_name, this->stack_.top());

    content->decr();
}

void esl::Vm::load_attribut(esl::Bytecode* instr)
{
    esl::Object* object = dynamic_cast<esl::Object*>(stack_.top()->data_get());
    esl::GCObject* value = nullptr;
    std::string attr_name = *(RoData::instance_get()->get(instr->get_param()));

    if (object == nullptr)
        throw esl::Exception("Cannot access to attribut from non object");

    value = object->attribut_get(attr_name);
    value->incr();

    this->pop();
    this->stack_.push(value);
}

void esl::Vm::make_attribut (esl::Bytecode* instr)
{
    std::string attr_name = *(RoData::instance_get()->get(instr->get_param()));

    esl::Squeleton::get()->register_attribut(declaration->type_name_get(),
                                             attr_name);
}

void esl::Vm::create_type (esl::Bytecode* instr)
{
    std::string class_name = *(RoData::instance_get()->get(instr->get_param()));

    declaration = new esl::Type(class_name);
    declaration->init();
}

bool esl::Vm::external_call (esl::Function* fun, const esl::Params& params)
{
    esl::GCObject* ret_value = nullptr;
    esl::Context* fun_runtime = new esl::Context(*(this->runtime_));

    if ((ret_value = fun->call(fun_runtime, params)) == nullptr)
    {
        // Push current context in the stack
        this->stack_.push(new esl::GCObject(this->runtime_));

        // This is a ESL coded function
        for (int i = params.count() - 1; i >= 0; --i)
            this->stack_.push(params.get_params(i + 1));

        // Set function runtime as current runtime
        this->runtime_ = fun_runtime;

        return false;
    }
    else
    {
        delete fun_runtime;
        this->stack_.push(ret_value);
        return true;
    }
}

void esl::Vm::instanciation (esl::Bytecode* instr)
{
    std::string type;
    esl::Function* fun;
    esl::Params params;

    // Storing all args before context switch
    while (!dynamic_cast<esl::StackDelimiter*>(this->stack_.top()->data_get()))
    {
        params.params_set(this->stack_.top());
        this->stack_.pop();
    }

    // POP delimiter
    this->pop();

    // Get function name in RoData
    type = *(RoData::instance_get()->get(instr->get_param()));

    // Get function
    fun = esl::Squeleton::get()->method_get(type, "construct");

    esl::Object* object = new esl::Object(type);

    params.push_back(new esl::GCObject(object));

    if (external_call(fun, params))
        params.decr();
}

void esl::Vm::call_method(esl::Bytecode *instr)
{
    std::string fun_name;
    esl::GCObject* object_container = nullptr;
    esl::GCObject* ret_value = nullptr;
    esl::Object* object = nullptr;
    esl::Context* fun_runtime = new esl::Context(*(this->runtime_));
    esl::Params params;

    // Storing all args before context switch
    while (!dynamic_cast<esl::StackDelimiter*>(this->stack_.top()->data_get()))
    {
        params.params_set(this->stack_.top());
        this->stack_.pop();
    }

    // POP the delimiter
    this->pop();

    // Get the object
    object_container = this->stack_.top();
    object = dynamic_cast<esl::Object*> (object_container->data_get());
    this->stack_.pop();

    // Set the the object itself as first param
    params.params_set(object_container);

    if (object == nullptr)
        throw esl::Exception("Method call on non object value");

    // Get the method name
    fun_name = *(RoData::instance_get()->get(instr->get_param()));

    // Perform the call
    if ((ret_value = object->call_method(fun_name, fun_runtime, params)) == nullptr)
    {
        object_container->incr();
        // Push current context in the stack
        this->stack_.push(new esl::GCObject(this->runtime_));

        // This is a ESL coded function
        for (int i = params.count() - 1; i >= 0; --i)
            this->stack_.push(params.get_params(i + 1));

        // Set function runtime as current runtime
        this->runtime_ = fun_runtime;
    }
    else // External function call
    {
        for (int i = 2; i <= params.count(); ++i)
            params.get_params(i)->decr();

        delete fun_runtime;
        this->stack_.push(ret_value);
    }

    // Decrement object counter since it has been poped
    object_container->decr();
}

void esl::Vm::operation (const std::string& name)
{
    esl::GCObject* obj1 = nullptr;
    esl::GCObject* obj2 = nullptr;

    obj1 = this->stack_.top();
    this->stack_.pop();

    obj2 = this->stack_.top();
    this->stack_.pop();

    // Get the 2 operands
    esl::Object* value1 = dynamic_cast<esl::Object*> (obj1->data_get());
    esl::Object* value2 = dynamic_cast<esl::Object*> (obj2->data_get());

    if (value1 && value2)
    {
        esl::Params params;

        // Setup params for operator call
        params.params_set(obj1);
        params.params_set(obj2);

        esl::Context* fun_context = new esl::Context();
        esl::GCObject* ret_value = nullptr;

        // Call operator function
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
    this->stack_.push(new esl::GCObject(delim));
}

void esl::Vm::pop()
{
    this->stack_.top()->decr();
    this->stack_.pop();
}

void esl::Vm::store_stk ()
{
    esl::GCObject* tos = nullptr;
    esl::GCObject* tos1 = nullptr;

    tos = this->stack_.top();
    this->stack_.pop();

    tos1 = this->stack_.top();
    this->stack_.pop();

    // Delete overrided data
    delete tos->data_get();

    // Setup new data
    tos->data_set(tos1->data_get());

    // Delete tos1 object without it data
    tos1->free();

    this->stack_.push(tos);
}

std::string esl::Vm::module_path(const std::string& mod_name)
{
    // Try to locate the called module
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

    // Setup new module and load it
    module = new esl::Module(path, *module_name);
    module->load();

    this->runtime_->module_set(*module_name, new esl::GCObject(module));
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
    esl::Context context;

    module = dynamic_cast<esl::Module*>(this->stack_.top()->data_get());
    this->stack_.pop();

    // Storing all args
    while (!dynamic_cast<esl::StackDelimiter*> (this->stack_.top()->data_get()))
    {
        params.params_set(this->stack_.top());
        this->stack_.pop();
    }

    // POP the delimiter
    this->pop();

    if (!module->is_registered(*fun_name))
        throw esl::Exception("no function " + *fun_name +
                             " registered in module " + module->name_get()); 
    // Perform the call
    this->stack_.push(module->call(*fun_name, params, &context));

    // Decrement reference count on all params (since they have been poped)
    params.decr();
}

void esl::Vm::load_int (Bytecode* instr)
{
    esl::IntObject* v = new esl::IntObject(instr->get_param());

    this->stack_.push(new esl::GCObject(v));
}

void esl::Vm::load_str (Bytecode* instr)
{
    esl::StringObject* v = nullptr;
    // Get string in RoData
    std::string str = *(RoData::instance_get()->get(instr->get_param()));

    v = new esl::StringObject(str);

    this->stack_.push(new esl::GCObject(v));
}

void esl::Vm::function_return()
{
    std::stack<esl::GCObject*> ret;

    while (this->stack_.top() &&
           !dynamic_cast<esl::Context*> (this->stack_.top()->data_get()))
    {
        ret.push(this->stack_.top());
        this->stack_.pop();
    }

    // Delete the current runtime since it is not needed anymore
    delete this->runtime_;

    // Restore the previous context
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
        this->stack_.push(new MemoryObject<esl::Content>(new esl::IntObject(0)));
}

void esl::Vm::call_function(esl::Bytecode *instr)
{
    std::string fun_name;
    esl::Function* fun;
    esl::Params params;
    esl::Context* fun_runtime = new esl::Context(*(this->runtime_));

    // Storing all args before context switch
    while (!dynamic_cast<esl::StackDelimiter*>(this->stack_.top()->data_get()))
    {
        params.params_set(this->stack_.top());
        this->stack_.pop();
    }

    // POP delimiter
    this->pop();

    // Push current context in the stack
    this->stack_.push(new esl::GCObject(this->runtime_));

    // Get function name in RoData
    fun_name = *(RoData::instance_get()->get(instr->get_param()));

    // Get function
    fun = dynamic_cast<esl::Function*>(runtime_->function_get(fun_name)->data_get());

    // Perform the call
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

    // Get the var name in RoData
    var_name = RoData::instance_get()->get(instr->get_param());

    if (dynamic_cast<esl::Context*> (this->stack_.top()->data_get()))
        throw esl::Exception("Internal error on store value");

    // Store the value
    this->runtime_->variable_set(*var_name, this->stack_.top());
}

void esl::Vm::load(esl::Bytecode *instr)
{
    std::string* var_name = nullptr;
    esl::GCObject* value = nullptr;

    // Get variable name in RoData
    var_name = RoData::instance_get()->get(instr->get_param());

    // Get the value of the variable
    value = this->runtime_->variable_get(*var_name);

    // Increment the reference count since it will be pushed on the stack
    value->incr();

    this->stack_.push(value);
}

void esl::Vm::jump(esl::Bytecode *instr, int val)
{
    // Check if conditional jump is performed over boolean expression
    if (dynamic_cast<esl::IntObject*> (this->stack_.top()->data_get()))
    {
        esl::IntObject* value = dynamic_cast<esl::IntObject*> (this->stack_.top()->data_get());
        int v = value->data_get();

        // If val is equal to TOS jump
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
    std::string fun_name = *(RoData::instance_get()->get(instr->get_param()));
    esl::Function* fun = nullptr;

    // Create the function
    fun = new esl::Function(this->runtime_->pc_get());

    if (!declaration)
        this->runtime_->function_set(fun_name, new esl::GCObject(fun));
    else
        esl::Squeleton::get()->register_method(declaration->type_name_get(),
                                               fun_name,
                                               fun);
}
