#include "context.hh"

esl::Context::Context()
    : functions_ ()
    , variables_ ()
    , modules_ ()
    , types_ ()
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
    for (auto mod : modules_)
        mod.second->decr();
    for (auto var : variables_)
        var.second->decr();
    for (auto fun : functions_)
        fun.second->decr();
}

esl::MemContent esl::Context::function_get (const std::string& name) const
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
    if (this->modules_.find(name) == this->modules_.end())
        throw Exception("Module " + name + " not found");

    return this->modules_.at(name);
}

esl::Constructor esl::Context::type_get (const std::string& name) const
{
    if (this->types_.find(name) == this->types_.end())
        throw Exception("Type " + name + " not found");

    return this->types_.at(name);
}

void esl::Context::variable_set (const std::string& name, MemContent value)
{
    value->incr();

    if (this->variables_.find(name) != this->variables_.end())
        this->variables_[name]->decr();

    this->variables_[name] = value;
}

void esl::Context::function_set (const std::string& name,
                                 MemContent function)
{
    this->functions_[name] = function;
}

void esl::Context::module_set (const std::string& name, MemContent module)
{
    std::string str = name;

    str[0] = str[0] - 'a' + 'A';

    this->modules_[str] = module;
}

void esl::Context::type_set (const std::string& name, Constructor value)
{
    this->types_[name] = value;
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
