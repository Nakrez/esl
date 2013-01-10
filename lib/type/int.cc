#include "int.hh"
#include "string.hh"
#include <cmath>

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

esl::MemoryObject<esl::Content>* esl::Int::to_string (const Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::String("Int"));
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

esl::MemoryObject<esl::Content>* esl::Int::pow_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();
    int powered = pow(data_, value);

    return new esl::MemoryObject<esl::Content>(new esl::Int(powered));
}

esl::MemoryObject<esl::Content>* esl::Int::eq_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ == value));
}

esl::MemoryObject<esl::Content>* esl::Int::diff_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ != value));
}

esl::MemoryObject<esl::Content>* esl::Int::gt_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ > value));
}

esl::MemoryObject<esl::Content>* esl::Int::ge_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ >= value));
}

esl::MemoryObject<esl::Content>* esl::Int::lt_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ < value));
}

esl::MemoryObject<esl::Content>* esl::Int::le_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ <= value));
}


esl::MemoryObject<esl::Content>* esl::Int::and_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ && value));
}

esl::MemoryObject<esl::Content>* esl::Int::or_op (const Params& params)
{
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
    int value = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::Int(data_ || value));
}
