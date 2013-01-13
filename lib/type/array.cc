#include "array.hh"
#include "string.hh"
#include "int-object.hh"

esl::Array::Array (unsigned int size)
    : Type ("Array")
{
    for (unsigned i = 0; i < size; ++i)
        data_.push_back(new esl::MemoryObject<esl::Content>(new esl::IntObject(0)));
}

esl::Array::~Array ()
{
    for (auto v : data_)
        v->decr();
}

esl::MemoryObject<esl::Content>* esl::Array::instanciate ()
{
    return new esl::MemoryObject<esl::Content>(new esl::Array(0));
}

esl::MemoryObject<esl::Content>* esl::Array::bracket_op (const Params& params)
{
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    unsigned int pos = op2->data_get();

    if (pos >= data_.size ())
        throw Exception ("Illegal access : out of bound");

    data_.at (pos)->incr ();

    return data_.at (pos);
}

esl::MemoryObject<esl::Content>* esl::Array::print (const esl::Params&)
{
    std::cout << "[" << std::endl;

    std::cout << "]" << std::endl;

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::Array::to_string (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::String("Array"));
}

std::string esl::Array::type_name_get () const
{
    return "Array";
}
