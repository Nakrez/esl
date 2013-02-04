#include "stack-object.hh"
#include "../../lib/type/int-object.hh"

esl::StackObject::StackObject ()
    : Object ("stack")
{

}

esl::StackObject::~StackObject ()
{
    while (!data_.empty())
    {
        data_.top()->decr();
        data_.pop();
    }
}

int esl::StackObject::size () const
{
    return data_.size();
}

int esl::StackObject::empty () const
{
    return data_.empty();
}

void esl::StackObject::pop ()
{
    if (data_.empty())
        return;

    data_.top()->decr();
    data_.pop();
}

void esl::StackObject::push (esl::GCObject* obj)
{
    data_.push(obj);
}

esl::GCObject* esl::StackObject::top () const
{
    if (data_.empty())
        throw esl::Exception("Top perform on an empty stack");

    data_.top()->incr();
    return data_.top();
}
