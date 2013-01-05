#include "array.hh"
# include "../gc/memory-object.hh"

esl::Array::Array (unsigned int size)
{
    for (unsigned i = 0; i < size; ++i)
        data_.push_back(new esl::MemoryObject<esl::Content>(new Int(0)));
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
    esl::Int* op2 = dynamic_cast<esl::Int*>(params.get_params(2)->data_get());
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

    return new esl::MemoryObject<esl::Content> (new esl::Int(0));
}

std::string esl::Array::type_name_get () const
{
    return "Array";
}
