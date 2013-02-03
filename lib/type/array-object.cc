#include "array-object.hh"
#include "../../lib/type/int-object.hh"

esl::ArrayObject::ArrayObject ()
    : Object ("array")
{

}

esl::ArrayObject::ArrayObject (int size)
    : Object ("array")
{
    data_.resize(size);

    for (int i = 0; i < size; ++i)
        data_[i] = new esl::MemoryObject<esl::Content>(new esl::IntObject(0));
}

esl::ArrayObject::~ArrayObject ()
{
    for (auto v : data_)
        v->decr();
}

esl::MemoryObject<esl::Content>* esl::ArrayObject::at (int i)
{
    if (static_cast<unsigned> (i) >= data_.size())
        throw esl::Exception ("Array module : Illegal access (out of bound)");

    return data_.at(i);
}

int esl::ArrayObject::size () const
{
    return data_.size();
}

void esl::ArrayObject::put_at (int i, esl::MemoryObject<esl::Content>* obj)
{
    if (i < 0 || static_cast<unsigned> (i) >= data_.size())
        throw esl::Exception ("Array module : Illegal access (out of bound)");

    data_[i] = obj;
}

void esl::ArrayObject::push_back (esl::MemoryObject<esl::Content>* obj)
{
    data_.push_back(obj);
}
