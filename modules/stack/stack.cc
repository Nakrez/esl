#include "stack.hh"
#include "../../lib/type/string-object.hh"
#include "../../lib/type/int-object.hh"
#include "stack-object.hh"

esl::Stack::Stack ()
    : Type ("stack")
{
}

esl::Stack::~Stack ()
{
}

void esl::Stack::init ()
{
    esl::Squeleton* squeleton = esl::Squeleton::get();

    this->init_basics();

    squeleton->register_method (name_, "empty",
                                new Function(new Delegate<esl::Stack>(this,
                                                                      &esl::Stack::empty)));
    squeleton->register_method (name_, "size",
                                new Function(new Delegate<esl::Stack>(this,
                                                                      &esl::Stack::size)));
    squeleton->register_method (name_, "top",
                                new Function(new Delegate<esl::Stack>(this,
                                                                      &esl::Stack::top)));
    squeleton->register_method (name_, "pop",
                                new Function(new Delegate<esl::Stack>(this,
                                                                      &esl::Stack::pop)));
    squeleton->register_method (name_, "push",
                                new Function(new Delegate<esl::Stack>(this,
                                                                      &esl::Stack::push)));
}

esl::GCObject* esl::Stack::construct (const Params&)
{
    esl::StackObject* array = new esl::StackObject();

    return new esl::GCObject(array);
}

esl::GCObject* esl::Stack::print (const esl::Params&)
{
    std::cout << "STACK" << std::endl;

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::Stack::to_string (const esl::Params&)
{
    return new esl::GCObject (new esl::StringObject("Stack"));
}

esl::GCObject* esl::Stack::pop (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    op1->pop();

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::Stack::top (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    return op1->top();
}

esl::GCObject* esl::Stack::empty (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    return new esl::GCObject(new esl::IntObject(op1->empty()));
}

esl::GCObject* esl::Stack::size (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    return new esl::GCObject(new esl::IntObject(op1->size()));
}

esl::GCObject* esl::Stack::push (const Params& params)
{
    esl::StackObject* op1 = nullptr;
    esl::GCObject* op2 = nullptr;

    if (params.count() == 1)
        throw esl::Exception ("Not enought parameters to push");

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());
    op2 = params.get_params(2);

    op2->incr();

    op1->push(op2);

    return new esl::GCObject (new esl::IntObject(0));
}
