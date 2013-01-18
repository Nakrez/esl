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

esl::MemoryObject<esl::Content>* esl::Stack::construct (const Params&)
{
    esl::StackObject* array = new esl::StackObject();

    return new esl::MemoryObject<esl::Content>(array);
}

esl::MemoryObject<esl::Content>* esl::Stack::print (const esl::Params&)
{
    std::cout << "STACK" << std::endl;

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::Stack::to_string (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::StringObject("Stack"));
}

esl::MemoryObject<esl::Content>* esl::Stack::pop (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    op1->pop();

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::Stack::top (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    return op1->top();
}

esl::MemoryObject<esl::Content>* esl::Stack::empty (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(op1->empty()));
}

esl::MemoryObject<esl::Content>* esl::Stack::size (const Params& params)
{
    esl::StackObject* op1 = nullptr;

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(op1->size()));
}

esl::MemoryObject<esl::Content>* esl::Stack::push (const Params& params)
{
    esl::StackObject* op1 = nullptr;
    esl::MemoryObject<esl::Content>* op2 = nullptr;

    if (params.count() == 1)
        throw esl::Exception ("Not enought parameters to push");

    op1 = dynamic_cast<esl::StackObject*>(params.get_params(1)->data_get());
    op2 = params.get_params(2);

    op2->incr();

    op1->push(op2);

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}
