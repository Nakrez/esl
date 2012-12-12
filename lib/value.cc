#include "value.hh"

esl::Value::Value() : esl::ContentObject ()
{
}

esl::Value::Value(obj_type type, void* content)
    : esl::ContentObject (type, content)
{
}

esl::Value::Value(const esl::Value& v)
    : esl::ContentObject (v.type_, v.content_)
{
}

esl::Value::~Value()
{
    if (this->type_ == O_INT)
        delete ((int*)this->content_);
    else if (this->type_ == O_STRING)
        delete ((std::string*)this->content_);
}

void esl::Value::print()
{
    if (this->type_ == O_INT)
        std::cout << *((int *)this->content_);
    else if (this->type_ == O_STRING)
        std::cout << *((std::string *)this->content_);
    else if (this->type_ == O_NIL)
        std::cout << "nil";
}
