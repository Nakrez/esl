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

esl::MemoryObject<esl::Content>* esl::String::print (const esl::Params&)
{
    std::cout << data_;

    return new esl::MemoryObject<esl::Content> (new esl::Int(0));
}

std::string esl::String::type_name_get () const
{
    return "String";
}

esl::MemoryObject<esl::Content>* esl::String::plus_op (const Params& params)
{
    esl::String* op2 = dynamic_cast<esl::String*>(params.get_params(2)->data_get());
    std::string value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::String(data_ + value));
}
