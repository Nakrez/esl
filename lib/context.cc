#include "context.hh"

esl::ContentObject* esl::std_callback (esl::Runtime*, esl::Params*)
{
    return nullptr;
}

esl::Context::Context()
    : Object ()
{
    this->functions_ = new std::map<std::string, std::pair<esl::Callback, int>>();
    this->variables_ = new std::map<std::string, esl::Value*>();
}

esl::Context::Context(const Context& context)
    : Object ()
{
    this->functions_ = new std::map<std::string, std::pair<esl::Callback, int>>(*(context.functions_));
    this->variables_ = new std::map<std::string, esl::Value*>();
}

esl::Context::~Context()
{
    delete this->functions_;
    delete this->variables_;
}

std::pair<esl::Callback, int> esl::Context::function_get (const std::string& name) const
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

void esl::Context::function_set (const std::string& name,
                                 esl::Callback call,
                                 int addr)
{
    (*(this->functions_))[name] = std::pair<esl::Callback, int>(call, addr);
}
