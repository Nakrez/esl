#include "context.hh"
#include "module.hh"

esl::Context::Context()
    : functions_ ()
    , variables_ ()
    , modules_ ()
    , pc_ (0)
{
}

esl::Context::Context(const Context& context)
{
    for (auto mod : context.modules_)
        mod.second->incr();

    for (auto fun : context.functions_)
        fun.second->incr();

    modules_ = context.modules_;
    functions_ = context.functions_;
}

esl::Context::~Context()
{
    for (auto var : variables_)
        var.second->decr();
    for (auto fun : functions_)
        fun.second->decr();
    for (auto mod : modules_)
        mod.second->decr();
}

bool esl::Context::function_exist(const std::string& name) const
{
    return this->functions_.find(name) != this->functions_.end();
}

bool esl::Context::module_function(const std::string& module,
                                   const std::string& fun) const
{
    std::string str = module;

    for (unsigned i = 1; i < str.length(); ++i)
        str[i] = tolower(str[i]);

    str[0] = toupper(str[0]);

    if (!module_exist(str))
        return 0;

    esl::Module* ext = dynamic_cast<esl::Module*>(modules_.at(str)->data_get());
    return ext->is_registered(fun);
}

bool esl::Context::module_exist(const std::string& name) const
{
    std::string str = name;

    for (unsigned i = 1; i < str.length(); ++i)
        str[i] = tolower(str[i]);

    str[0] = toupper(str[0]);

    return this->modules_.find(str) != this->modules_.end();
}

bool esl::Context::variable_exist(const std::string& name) const
{
    return this->variables_.find(name) != this->variables_.end();
}

esl::GCObject* esl::Context::function_get (const std::string& name) const
{
    if (this->functions_.find(name) == this->functions_.end())
        throw Exception("Function " + name + " not found");

    return this->functions_.at(name);
}

esl::GCObject* esl::Context::variable_get (const std::string& name) const
{
    if (this->variables_.find(name) == this->variables_.end())
        throw Exception("Variable " + name + " not found");

    return this->variables_.at(name);
}

esl::GCObject* esl::Context::module_get (const std::string& name) const
{
    if (this->modules_.find(name) == this->modules_.end())
        throw Exception("Module " + name + " not found");

    return this->modules_.at(name);
}

void esl::Context::variable_set (const std::string& name, esl::GCObject* value)
{
    value->incr();

    if (this->variables_.find(name) != this->variables_.end())
        this->variables_[name]->decr();

    this->variables_[name] = value;
}

void esl::Context::function_set (const std::string& name,
                                 GCObject* function)
{
    this->functions_[name] = function;
}

void esl::Context::module_set (const std::string& name, GCObject* module)
{
    std::string str = name;

    str[0] = toupper(str[0]);

    this->modules_[str] = module;
}

size_t esl::Context::pc_get () const
{
    return this->pc_;
}

void esl::Context::pc_set (size_t pc)
{
    this->pc_ = pc;
}

void esl::Context::pc_incr (int incr)
{
    this->pc_ += incr;
}
