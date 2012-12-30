#include "params.hh"

esl::Params::Params ()
{

}

esl::Params::~Params ()
{
}

bool esl::Params::empty () const
{
    return this->params_.empty();
}

int esl::Params::count () const
{
    return this->params_.size();
}

esl::Value* esl::Params::get_params (int number) const
{
    return this->params_.at(number - 1);
}

void esl::Params::params_set (Value* value)
{
    return this->params_.push_front(value);
}
