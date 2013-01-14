#include "int-object.hh"

esl::IntObject::IntObject (int data)
    : Object ("Int")
    , data_ (data)
{

}

int esl::IntObject::data_get () const
{
    return data_;
}

void esl::IntObject::data_set (int data)
{
    data_ = data;
}
