#include "function.hh"

esl::Function::Function ()
{

}

esl::Function::~Function ()
{

}

std::string esl::Function::get_name() const
{
    return this->name_;
}

esl::ContentObject* esl::Function::call(Runtime* runtime, Params* params)
{
    if (this->callback_ == nullptr)
        throw std::exception();
    else
        return this->callback_(runtime, params);
}
