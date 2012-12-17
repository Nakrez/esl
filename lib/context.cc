#include "context.hh"

esl::ContentObject* esl::std_callback (esl::Runtime*, esl::Params*)
{
    return nullptr;
}

esl::Context::Context()
    : Object ()
    , functions_ ()
    , variables_ ()
    , modules_ ()
{
}

esl::Context::Context(const Context& context)
    : Object ()
    , functions_ (context.functions_)
    , variables_ (context.variables_)
    , modules_ (context.modules_)
{

}

esl::Context::~Context()
{
}

std::pair<esl::Callback, int> esl::Context::function_get (const std::string& name) const
{
    return this->functions_.at(name);
}

esl::Value* esl::Context::variable_get (const std::string& name) const
{
    if (this->variables_.find(name) == this->variables_.end())
    {
        std::cout << "Variable " << name << " not found" << std::endl;
        exit(1);
    }

    return this->variables_.at(name).get();
}

esl::Module* esl::Context::module_get (const std::string& name) const
{
    return this->modules_.at(name).get();
}

void esl::Context::variable_set (const std::string& name, esl::Value* value)
{
    if (this->variables_.find(name) != this->variables_.end())
        this->variables_.at(name)->decr_ref();

    this->variables_[name] = ValuePtr(value);
}

void esl::Context::function_set (const std::string& name,
                                 esl::Callback call,
                                 int addr)
{
    this->functions_[name] = std::pair<esl::Callback, int>(call, addr);
}

void esl::Context::module_set (const std::string& name, esl::Module* module)
{
    this->modules_[name] = ModulePtr(module);
}
