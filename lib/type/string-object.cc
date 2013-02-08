#include "string-object.hh"

esl::StringObject::StringObject()
    : Object("String")
{

}

esl::StringObject::StringObject(const std::string& data)
    : Object("String")
    , data_(data)
{

}

const std::string& esl::StringObject::data_get() const
{
    return data_;
}

void esl::StringObject::data_set(const std::string& data)
{
    data_ = data;
}

void esl::StringObject::erase(int start, int len)
{
    data_.erase(start, len);
}

void esl::StringObject::replace(int start, int len, const std::string& str)
{
    data_.replace(start, len, str);
}
