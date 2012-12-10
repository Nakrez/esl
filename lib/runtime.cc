#include "runtime.hh"

esl::Runtime::Runtime ()
    : Context ()
    , pc_ (0)
{

}

esl::Runtime::Runtime(const Runtime& runtime)
    : Context (runtime)
{
}

esl::Runtime::~Runtime ()
{

}

size_t esl::Runtime::pc_get () const
{
    return this->pc_;
}

void esl::Runtime::pc_set (size_t pc)
{
    this->pc_ = pc;
}

void esl::Runtime::pc_incr (int incr)
{
    this->pc_ += incr;
}
