#include "context.hh"

esl::Context::Context()
    : Object ()
{
    this->functions_ = new std::map<std::string, esl::Function*>();
}

esl::Context::~Context()
{
}

esl::Function* esl::Context::function_get (const std::string& name) const
{
    return this->functions_->at(name);
}
