#include "content-object.hh"

esl::ContentObject::ContentObject ()
    : esl::Object ()
{

}

esl::ContentObject::~ContentObject ()
{

}

void* esl::ContentObject::content_get () const
{
    return this->content_;
}

obj_type esl::ContentObject::type_get () const
{
    return this->type_;
}
