#include "string.hh"
#include "int-object.hh"
#include "string-object.hh"
#include "array-object.hh"

esl::String::String ()
    : Type ("String")
{

}

esl::String::~String ()
{

}

void esl::String::init()
{
    esl::Squeleton& squeleton = esl::Squeleton::get();

    init_basics();

    squeleton.register_method(name_, "size",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::size)));

    squeleton.register_method(name_, "at",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::at)));

    squeleton.register_method(name_, "split",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::split)));

    squeleton.register_method(name_, "to_int",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::to_int)));

    squeleton.register_method(name_, "empty",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::empty)));

    squeleton.register_method(name_, "insert",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::insert)));

    squeleton.register_method(name_, "erase",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::erase)));

    squeleton.register_method(name_, "replace",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::replace)));

    squeleton.register_method(name_, "substr",
                              new Function(new Delegate<esl::String>(this,
                                                                     &esl::String::substr)));
}

esl::GCObject* esl::String::construct (const Params&, Context*)
{
    return new esl::GCObject(new esl::IntObject(0));
}

esl::GCObject* esl::String::replace(const esl::Params& params, Context*)
{
    if (params.count() < 4)
        throw esl::Exception("replace takes 3 parameters");

    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::IntObject* start = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    esl::IntObject* len = dynamic_cast<esl::IntObject*>(params.get_params(3)->data_get());
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(4)->data_get());

    if (!start)
        throw esl::Exception("1st parameter of replace must be an integer");

    if (!len)
        throw esl::Exception("2nd parameter of replace must be an integer");

    if (!str)
        throw esl::Exception("2nd parameter of replace must be a string");

    obj->replace(start->data_get(), len->data_get(), str->data_get());
    params.get_params(1)->incr();

    return params.get_params(1);
}

esl::GCObject* esl::String::substr(const esl::Params& params, Context*)
{
    if (params.count() < 3)
        throw esl::Exception("substr takes 2 parameters");

    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::IntObject* start = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    esl::IntObject* len = dynamic_cast<esl::IntObject*>(params.get_params(3)->data_get());

    if (!start)
        throw esl::Exception("1st parameter of substr must be an integer");

    if (!len)
        throw esl::Exception("2nd parameter of substr must be an integer");

    esl::StringObject* sub = new esl::StringObject(obj->substr(start->data_get(),
                                                               len->data_get()));
    return new GCObject(sub);
}

esl::GCObject* esl::String::erase (const esl::Params& params, Context*)
{
    if (params.count() < 3)
        throw esl::Exception("erase takes 2 parameters");

    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::IntObject* start = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    esl::IntObject* len = dynamic_cast<esl::IntObject*>(params.get_params(3)->data_get());

    if (!start)
        throw esl::Exception("1st parameter of erase must be an integer");

    if (!len)
        throw esl::Exception("2nd parameter of erase must be an integer");


    obj->erase(start->data_get(), len->data_get());
    params.get_params(1)->incr();

    return params.get_params(1);
}

esl::GCObject* esl::String::insert (const esl::Params& params, Context*)
{
    if (params.count() < 3)
        throw esl::Exception("insert takes 2 parameters");

    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::IntObject* pos = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(3)->data_get());

    if (!pos)
        throw esl::Exception("1st parameter of insert must be an integer");

    if (!str)
        throw esl::Exception("2nd parameter of insert must be a string");

    std::string temp = obj->data_get();

    obj->data_set(temp.insert(pos->data_get(), str->data_get()));

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::String::empty (const esl::Params& params, Context*)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    int ret = obj->data_get().empty();

    return new esl::GCObject (new esl::IntObject(ret));
}

esl::GCObject* esl::String::print (const esl::Params& params, Context*)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    std::cout << obj->data_get();

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::String::to_int (const esl::Params& params, Context*)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    int ret = atoi(obj->data_get().c_str());

    return new esl::GCObject (new esl::IntObject(ret));
}

esl::GCObject* esl::String::to_string (const esl::Params& params, Context*)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    std::string value = obj->data_get();

    return new esl::GCObject (new esl::StringObject(value));
}

esl::GCObject* esl::String::size (const esl::Params& params, Context*)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    std::string value = obj->data_get();

    return new esl::GCObject (new esl::IntObject(value.size()));
}

esl::GCObject* esl::String::at (const esl::Params& params, Context*)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::IntObject* pos = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    std::string value;

    if (pos->data_get() >= 0 &&
        static_cast<unsigned>(pos->data_get()) < obj->data_get().size())
        value = std::string(1, obj->data_get().at(pos->data_get()));

    return new esl::GCObject(new esl::StringObject(value));
}

esl::GCObject* esl::String::split (const esl::Params& params, Context*)
{
    esl::StringObject* obj = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::ArrayObject* ret = new esl::ArrayObject();
    char delim;
    std::istringstream buf(obj->data_get());

    if (params.count() <= 1)
        delim = ' ';
    else
    {
        esl::StringObject* del = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
        if (del->data_get().size() <= 0 || del->data_get().size() > 1)
            throw esl::Exception("1st parmeter of split must be a uniq char");

        delim = del->data_get().at(0);
    }

    for(std::string token; getline(buf, token, delim); )
        ret->push_back(new esl::GCObject(new esl::StringObject(token)));

    return new esl::GCObject (ret);
}

std::string esl::String::type_name_get () const
{
    return name_;
}

esl::GCObject* esl::String::plus_op (const Params& params, Context*)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::GCObject(new esl::StringObject(value1 + value2));
}

esl::GCObject* esl::String::eq_op (const Params& params, Context*)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 == value2));
}

esl::GCObject* esl::String::diff_op (const Params& params, Context*)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 != value2));
}

esl::GCObject* esl::String::gt_op (const Params& params, Context*)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 > value2));
}

esl::GCObject* esl::String::ge_op (const Params& params, Context*)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 >= value2));
}

esl::GCObject* esl::String::lt_op (const Params& params, Context*)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 < value2));
}

esl::GCObject* esl::String::le_op (const Params& params, Context*)
{
    esl::StringObject* op1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* op2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());
    std::string value1 = op1->data_get();
    std::string value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 <= value2));
}
