#include <execute/esl_value.hh>

esl_value::esl_value()
{
    this->value = NULL;
    this->type = V_EMPTY;
}

esl_value::esl_value(enum value type, void *value)
{
    this->value = value;
    this->type = type;
}

esl_value::~esl_value()
{
    if (this->type == V_INT)
        delete ((int *)this->value);
    else if (this->type == V_STRING)
        delete ((std::string *)this->value);
}

void *esl_value::get_value()
{
    return this->value;
}

enum value esl_value::get_type()
{
    return this->type;
}

void esl_value::set_value(void *value)
{
    this->value = value;
}

void esl_value::set_type(enum value type)
{
    this->type = type;
}


