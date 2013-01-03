#include "int.hh"

esl::Int::Int (int data)
    : data_ (data)
{

}

esl::Int::~Int ()
{

}

int esl::Int::data_get () const
{
    return data_;
}

void esl::Int::data_set (int data)
{
    data_ = data;
}

esl::MemoryObject<esl::Content>* esl::Int::print (const Params&)
{
    std::cout << data_;

    return new esl::MemoryObject<esl::Content> (new esl::Int(0));
}

std::string esl::Int::type_name_get () const
{
    return "Int";
}
