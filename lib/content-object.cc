#include "content-object.hh"

esl::ContentObject::ContentObject ()
    : esl::Object ()
{

}

esl::ContentObject::ContentObject (obj_type type, void* content)
    : esl::Object ()
    , type_ (type)
    , content_ (content)
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

void esl::ContentObject::content_set (void* content)
{
    this->content_ = content;
}
