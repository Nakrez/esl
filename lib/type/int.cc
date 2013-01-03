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

esl::MemoryObject<esl::Content>* esl::Int::plus_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ + value));
}

esl::MemoryObject<esl::Content>* esl::Int::minus_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ - value));
}

esl::MemoryObject<esl::Content>* esl::Int::mul_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ * value));
}

esl::MemoryObject<esl::Content>* esl::Int::div_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ / value));
}

esl::MemoryObject<esl::Content>* esl::Int::mod_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ % value));
}
