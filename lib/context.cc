#include "context.hh"

esl::Context::Context()
    : Object ()
{
    this->functions_ = new std::map<std::string, esl::Function*>();
}

esl::Context::Context(const Context& context)
    : Object ()
{
    this->functions_ = new std::map<std::string, esl::Function*>(*(context.functions_));
}

esl::Context::~Context()
{
}

esl::Function* esl::Context::function_get (const std::string& name) const
{
    return this->functions_->at(name);
}

esl::Value* esl::Context::variable_get (const std::string& name) const
{
    return this->variables_->at(name);
}

void esl::Context::variable_set (const std::string& name, esl::Value* value)
{
    /* TODO : decr smart pointer */
    (*(this->variables_))[name] = value;
}
