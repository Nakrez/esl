#include "params.hh"

esl::Params::Params()
{

}

esl::Params::~Params()
{
}

bool esl::Params::empty() const
{
    return this->params_.empty();
}

int esl::Params::count() const
{
    return this->params_.size();
}

esl::MemoryObject<esl::Content>* esl::Params::get_params(int number) const
{
    return this->params_.at(number - 1);
}

void esl::Params::push_back(esl::MemoryObject<esl::Content>* value)
{
    this->params_.push_back(value);
}

void esl::Params::params_set(esl::MemoryObject<esl::Content>* value)
{
    this->params_.push_front(value);
}

void esl::Params::decr()
{
    for (auto obj : params_)
        obj->decr();
}
