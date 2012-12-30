#include "array.hh"
# include "../gc/memory-object.hh"

esl::Array::Array (unsigned int size)
{
    for (unsigned i = 0; i < size; ++i)
        data_.push_back(new esl::Value(O_NIL, nullptr));
}

esl::Array::~Array ()
{
    for (auto v : data_)
        delete v;
}

esl::Value* esl::Array::at (unsigned int pos)
{
    if (pos >= data_.size ())
        throw Exception ("Illegal access : out of bound");

    return data_.at (pos);
}
