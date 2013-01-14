#include "string-object.hh"

esl::StringObject::StringObject (const std::string& data)
    : Object ("String")
    , data_ (data)
{

}

const std::string& esl::StringObject::data_get () const
{
    return data_;
}

void esl::StringObject::data_set (const std::string& data)
{
    data_ = data;
}
