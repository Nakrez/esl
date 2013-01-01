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

void esl::Int::print () const
{
    std::cout << data_;
}
