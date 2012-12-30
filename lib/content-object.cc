#include "content-object.hh"

esl::ContentObject::ContentObject ()
    : esl::Object ()
    , type_ (O_NIL)
    , null (true)
{
}

esl::ContentObject::ContentObject (obj_type type, void* content)
    : esl::Object ()
    , type_ (type)
{
    content_set(content);
}

esl::ContentObject::~ContentObject ()
{
}

void* esl::ContentObject::content_get () const
{
    if (null)
        return nullptr;
    return this->content_.get();
}

obj_type esl::ContentObject::type_get () const
{
    return this->type_;
}

void esl::ContentObject::content_set (void* content)
{
    if (!content)
    {
        null = true;
        return;
    }
    else
        null = false;

    this->content_ = std::shared_ptr<void> (content);
}

void esl::ContentObject::type_set (obj_type type)
{
    this->type_ = type;
}
