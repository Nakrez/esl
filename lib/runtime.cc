#include "runtime.hh"

esl::Runtime::Runtime ()
    : Context ()
    , pc_ (0)
{

}

esl::Runtime::~Runtime ()
{

}

size_t esl::Runtime::pc_get () const
{
    return this->pc_;
}

void esl::Runtime::pc_incr (int incr)
{
    this->pc_ += incr;
}
