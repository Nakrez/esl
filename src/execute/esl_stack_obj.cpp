#include <execute/esl_stack_obj.hh>

esl_stack_obj::esl_stack_obj()
{
    this->type = S_EMPTY;
    this->object = NULL;
}

esl_stack_obj::esl_stack_obj(enum stack_type type, void *object)
{
    this->type = type;
    this->object = object;
}

esl_stack_obj::~esl_stack_obj()
{
    if (this->type == S_VAL)
        delete ((esl_value *) this->object);
    else if (this->type == S_CONTEXT)
        delete ((esl_context *) this->object);
}

void *esl_stack_obj::get_object()
{
    return this->object;
}

enum stack_type esl_stack_obj::get_type()
{
    return this->type;
}

void esl_stack_obj::set_object(void *object)
{
    this->object = object;
}

void esl_stack_obj::set_type(enum stack_type type)
{
    this->type = type;
}
