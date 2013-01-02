#include "context.hh"

esl::MemoryObject<esl::Content>* esl::std_callback (esl::Runtime*,
                                                    const esl::Params&)
{
    return nullptr;
}

esl::Context::Context()
    : functions_ ()
    , variables_ ()
    , modules_ ()
{
}

esl::Context::Context(const Context& context)
    : functions_ (context.functions_)
{
    for (auto mod : context.modules_)
        mod.second->incr();
    modules_ = context.modules_;
}

esl::Context::~Context()
{
    for (auto mod : modules_)
        mod.second->decr();
    for (auto var : variables_)
        var.second->decr();
}

std::pair<esl::Callback, int> esl::Context::function_get (const std::string& name) const
{
    if (this->functions_.find(name) == this->functions_.end())
        throw Exception("Function " + name + " not found");

    return this->functions_.at(name);
}

esl::MemContent esl::Context::variable_get (const std::string& name) const
{
    if (this->variables_.find(name) == this->variables_.end())
        throw Exception("Variable " + name + " not found");

    return this->variables_.at(name);
}

esl::MemContent esl::Context::module_get (const std::string& name) const
{
    return this->modules_.at(name);
}

void esl::Context::variable_set (const std::string& name, MemContent value)
{
    value->incr();

    if (this->variables_.find(name) != this->variables_.end())
        this->variables_[name]->decr();

    this->variables_[name] = value;
}

void esl::Context::function_set (const std::string& name,
                                 esl::Callback call,
                                 int addr)
{
    this->functions_[name] = std::pair<esl::Callback, int>(call, addr);
}

void esl::Context::module_set (const std::string& name, MemContent module)
{
    this->modules_[name] = module;
}
