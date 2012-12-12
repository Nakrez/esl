#include "object.hh"

esl::Object::Object ()
{
    this->ref_count_ = 0;
}

void esl::Object::incr_ref ()
{
    ++(this->ref_count_);
}

void esl::Object::decr_ref ()
{
    --(this->ref_count_);

    /*if (this->ref_count_ <= 0)
        delete this;*/
}

int esl::Object::ref_get () const
{
    return ref_count_;
}
