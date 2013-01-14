#include "array.hh"
#include "../../lib/type/string-object.hh"
#include "../../lib/type/int-object.hh"
#include "array-object.hh"

esl::Array::Array ()
    : Type ("Array")
{
}

esl::Array::~Array ()
{
}

esl::MemoryObject<esl::Content>* esl::Array::construct (const Params&)
{
    return new esl::MemoryObject<esl::Content>(new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::Array::bracket_op (const Params& params)
{
    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    unsigned int pos = op2->data_get();

    object->at(pos)->incr();

    return object->at(pos);
}

esl::MemoryObject<esl::Content>* esl::Array::print (const esl::Params&)
{
    std::cout << "[" << std::endl;

    std::cout << "]" << std::endl;

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::Array::to_string (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::StringObject("Array"));
}

std::string esl::Array::type_name_get () const
{
    return "Array";
}
