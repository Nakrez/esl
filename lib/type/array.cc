#include "array.hh"
#include "string-object.hh"
#include "int-object.hh"
#include "array-object.hh"

namespace esl
{
    Array::Array ()
        : Type ("array")
    {}

    Array::~Array ()
    {}

    void Array::init()
    {
        Squeleton& squeleton = Squeleton::get();

        init_basics();

        squeleton.register_method(name_, "size",
                                  new Function(new Delegate<Array>(this,
                                                                   &Array::size)));

        squeleton.register_method(name_, "at",
                                  new Function(new Delegate<Array>(this,
                                                                   &Array::at)));

        squeleton.register_method(name_, "put_at",
                                  new Function(new Delegate<Array>(this,
                                                                   &Array::put_at)));

        squeleton.register_method(name_, "push_back",
                                  new Function(new Delegate<Array>(this,
                                                                   &Array::push_back)));
    }

    GCObject* Array::construct (const Params& params, Context*)
    {
        ArrayObject* array = nullptr;

        if (params.count() == 1)
            array = new ArrayObject(0);
        else
        {
            IntObject* size = static_cast<IntObject*> (params.get_params(1)->data_get());
            array = new ArrayObject(size->data_get());
        }

        return new GCObject(array);
    }

    GCObject* Array::bracket_op (const Params& params, Context*)
    {
        ArrayObject* object = dynamic_cast<ArrayObject*>(params.get_params(1)->data_get());
        IntObject* op2 = dynamic_cast<IntObject*>(params.get_params(2)->data_get());
        unsigned int pos = op2->data_get();

        object->at(pos)->incr();

        return object->at(pos);
    }

    GCObject* Array::size (const Params& params, Context*)
    {
        ArrayObject* object = nullptr;
        object = dynamic_cast<ArrayObject*>(params.get_params(1)->data_get());

        return new GCObject(new IntObject(object->size()));
    }

    GCObject* Array::at (const Params& params, Context*)
    {
        if (params.count() <= 1)
            throw Exception("at takes 1 parameter");

        ArrayObject* object = dynamic_cast<ArrayObject*>(params.get_params(1)->data_get());
        IntObject* op2 = dynamic_cast<IntObject*>(params.get_params(2)->data_get());
        unsigned int pos = op2->data_get();

        object->at(pos)->incr();

        return object->at(pos);
    }

    GCObject* Array::push_back (const Params& params, Context*)
    {
        if (params.count() <= 1)
            throw Exception("at takes 1 parameter");

        ArrayObject* array = dynamic_cast<ArrayObject*>(params.get_params(1)->data_get());
        GCObject* obj = params.get_params(2);

        obj->incr();
        array->push_back(obj);

        return new GCObject(new IntObject(0));
    }

    GCObject* Array::put_at (const Params& params, Context*)
    {
        if (params.count() <= 2)
            throw Exception("at takes 2 parameter");

        ArrayObject* object = dynamic_cast<ArrayObject*>(params.get_params(1)->data_get());
        GCObject* value = params.get_params(3);
        IntObject* op2 = dynamic_cast<IntObject*>(params.get_params(2)->data_get());
        int pos = op2->data_get();

        object->put_at(pos, value);

        return new GCObject(new IntObject(0));
    }

    GCObject* Array::print (const Params&, Context*)
    {
        std::cout << "[" << std::endl;

        std::cout << "]" << std::endl;

        return new GCObject (new IntObject(0));
    }

    GCObject* Array::to_string (const Params&, Context*)
    {
        return new GCObject (new StringObject("Array"));
    }

    std::string Array::type_name_get () const
    {
        return "Array";
    }
} // namespace esl
