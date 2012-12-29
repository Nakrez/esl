#include "array.hh"

esl::Array::Array ()
{

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
