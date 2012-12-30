#include "string.hh"

esl::String::String (const std::string& data)
    : data_ (data)
{

}

esl::String::~String ()
{

}

const std::string& esl::String::data_get () const
{
    return data_;
}

void esl::String::data_set (const std::string& data)
{
    data_ = data;
}
