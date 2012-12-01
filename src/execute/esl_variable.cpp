#include <execute/esl_variable.hh>

esl_variable::esl_variable()
{

}

esl_variable::~esl_variable()
{

}

void *esl_variable::get_content()
{
    return this->content;
}

enum var_type esl_variable::get_type()
{
    return this->type;
}

void esl_variable::set_content(void *content)
{
    this->content = content;
}

void esl_variable::set_type(enum var_type type)
{
    this->type = type;
}
