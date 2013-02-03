#include "array.hh"
#include "../../lib/type/string-object.hh"
#include "../../lib/type/int-object.hh"
#include "array-object.hh"

esl::Array::Array ()
    : Type ("array")
{
}

esl::Array::~Array ()
{
}

void esl::Array::init()
{
    esl::Squeleton* squeleton = esl::Squeleton::get();

    init_basics();

    squeleton->register_method (name_, "size",
                                new Function(new Delegate<esl::Array>(this,
                                                                       &esl::Array::size)));

    squeleton->register_method (name_, "at",
                                new Function(new Delegate<esl::Array>(this,
                                                                       &esl::Array::at)));

    squeleton->register_method (name_, "put_at",
                                new Function(new Delegate<esl::Array>(this,
                                                                       &esl::Array::put_at)));
}

esl::MemoryObject<esl::Content>* esl::Array::construct (const Params& params)
{
    esl::ArrayObject* array = nullptr;

    if (params.count() == 1)
    {
        array = new esl::ArrayObject(0);
    }
    else
    {
        esl::IntObject* size = static_cast<esl::IntObject*> (params.get_params(1)->data_get());
        array = new esl::ArrayObject(size->data_get());
    }

    return new esl::MemoryObject<esl::Content>(array);
}

esl::MemoryObject<esl::Content>* esl::Array::bracket_op (const Params& params)
{
    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    unsigned int pos = op2->data_get();

    object->at(pos)->incr();

    return object->at(pos);
}

esl::MemoryObject<esl::Content>* esl::Array::size (const Params& params)
{
    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(object->size()));
}

esl::MemoryObject<esl::Content>* esl::Array::at (const Params& params)
{
    if (params.count() <= 1)
        throw esl::Exception("at takes 1 parameter");

    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    unsigned int pos = op2->data_get();

    object->at(pos)->incr();

    return object->at(pos);
}

esl::MemoryObject<esl::Content>* esl::Array::put_at (const Params& params)
{
    if (params.count() <= 2)
        throw esl::Exception("at takes 2 parameter");

    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::MemoryObject<esl::Content>* value = params.get_params(3);
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int pos = op2->data_get();

    object->put_at(pos, value);

    return new esl::MemoryObject<esl::Content>(new IntObject(0));
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
