#include "string.hh"
#include "int-object.hh"
#include "string-object.hh"

esl::String::String ()
    : Type ("String")
{

}

esl::String::~String ()
{

}

void esl::String::init()
{
    esl::Squeleton* squeleton = esl::Squeleton::get();

    init_basics();

    squeleton->register_method (name_, "size",
                                new Function(new Delegate<esl::String>(this,
                                                                       &esl::String::size)));

    squeleton->register_method (name_, "at",
                                new Function(new Delegate<esl::String>(this,
                                                                       &esl::String::at)));
}
esl::MemoryObject<esl::Content>* esl::String::construct (const Params&)
{
    return new esl::MemoryObject<esl::Content>(new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::String::print (const esl::Params& params)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    std::cout << obj->data_get();

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::String::to_string (const esl::Params& params)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    std::string value = obj->data_get();

    return new esl::MemoryObject<esl::Content> (new esl::StringObject(value));
}

esl::MemoryObject<esl::Content>* esl::String::size (const esl::Params& params)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    std::string value = obj->data_get();

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(value.size()));
}

esl::MemoryObject<esl::Content>* esl::String::at (const esl::Params& params)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::IntObject* pos = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    std::string value;

    if (pos->data_get() >= 0 &&
        static_cast<unsigned>(pos->data_get()) < obj->data_get().size())
        value = std::string(1, obj->data_get().at(pos->data_get()));

    return new esl::MemoryObject<esl::Content>(new esl::StringObject(value));
}

std::string esl::String::type_name_get () const
{
    return name_;
}

esl::MemoryObject<esl::Content>* esl::String::plus_op (const Params& params)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::StringObject(value1 + value2));
}

esl::MemoryObject<esl::Content>* esl::String::eq_op (const Params& params)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 == value2));
}

esl::MemoryObject<esl::Content>* esl::String::diff_op (const Params& params)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 != value2));
}

esl::MemoryObject<esl::Content>* esl::String::gt_op (const Params& params)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 > value2));
}

esl::MemoryObject<esl::Content>* esl::String::ge_op (const Params& params)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 >= value2));
}

esl::MemoryObject<esl::Content>* esl::String::lt_op (const Params& params)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 < value2));
}

esl::MemoryObject<esl::Content>* esl::String::le_op (const Params& params)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 <= value2));
}
