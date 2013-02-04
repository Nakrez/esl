#include "array.hh"
#include "string-object.hh"
#include "int-object.hh"
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

    squeleton->register_method (name_, "push_back",
                                new Function(new Delegate<esl::Array>(this,
                                                                       &esl::Array::push_back)));
}

esl::GCObject* esl::Array::construct (const Params& params, Context*)
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

    return new esl::GCObject(array);
}

esl::GCObject* esl::Array::bracket_op (const Params& params, Context*)
{
    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    unsigned int pos = op2->data_get();

    object->at(pos)->incr();

    return object->at(pos);
}

esl::GCObject* esl::Array::size (const Params& params, Context*)
{
    esl::ArrayObject* object = nullptr;
    object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());

    return new esl::GCObject(new esl::IntObject(object->size()));
}

esl::GCObject* esl::Array::at (const Params& params, Context*)
{
    if (params.count() <= 1)
        throw esl::Exception("at takes 1 parameter");

    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    unsigned int pos = op2->data_get();

    object->at(pos)->incr();

    return object->at(pos);
}

esl::GCObject* esl::Array::push_back (const Params& params, Context*)
{
    if (params.count() <= 1)
        throw esl::Exception("at takes 1 parameter");

    esl::ArrayObject* array = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::GCObject* obj = params.get_params(2);

    obj->incr();
    array->push_back(obj);

    return new esl::GCObject(new esl::IntObject(0));
}

esl::GCObject* esl::Array::put_at (const Params& params, Context*)
{
    if (params.count() <= 2)
        throw esl::Exception("at takes 2 parameter");

    esl::ArrayObject* object = dynamic_cast<esl::ArrayObject*>(params.get_params(1)->data_get());
    esl::GCObject* value = params.get_params(3);
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int pos = op2->data_get();

    object->put_at(pos, value);

    return new esl::GCObject(new IntObject(0));
}

esl::GCObject* esl::Array::print (const esl::Params&, Context*)
{
    std::cout << "[" << std::endl;

    std::cout << "]" << std::endl;

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::Array::to_string (const esl::Params&, Context*)
{
    return new esl::GCObject (new esl::StringObject("Array"));
}

std::string esl::Array::type_name_get () const
{
    return "Array";
}
