#include "esl.hh"

void Esl::init ()
{
    register_function("function_exist",
                      new esl::Delegate<Esl>(this, &Esl::function_exist));
    register_function("module_exist",
                      new esl::Delegate<Esl>(this, &Esl::module_exist));
    register_function("variable_exist",
                      new esl::Delegate<Esl>(this, &Esl::variable_exist));
    register_function("type_method",
                      new esl::Delegate<Esl>(this, &Esl::type_method));
    register_function("type_attribut",
                      new esl::Delegate<Esl>(this, &Esl::type_attribut));
    register_function("object_method",
                      new esl::Delegate<Esl>(this, &Esl::object_method));
    register_function("object_attribut",
                      new esl::Delegate<Esl>(this, &Esl::object_attribut));
    register_function("module_function",
                      new esl::Delegate<Esl>(this, &Esl::module_function));
}

esl::GCObject* Esl::function_exist(const esl::Params& params,
                                   esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("function_exist take 1 parameter");

    //esl::Vm* vm = esl::Vm::get();
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    if (!str)
        throw esl::Exception("1st parameter of function_exist must be a string");

    //int ret = vm->is_register_function(str->data_get());

    return new esl::GCObject(new esl::IntObject(0));//new esl::IntObject(ret));
}

esl::GCObject* Esl::module_exist(const esl::Params& params,
                                 esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("module_exist take 1 parameter");

    //esl::Vm* vm = esl::Vm::get();
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    if (!str)
        throw esl::Exception("1st parameter of module_exist must be a string");

    //int ret = vm->is_register_module(str->data_get());

    return new esl::GCObject(new esl::IntObject(0));//new esl::IntObject(ret));
}

esl::GCObject* Esl::variable_exist(const esl::Params& params,
                                   esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("variable_exist take 1 parameter");

    // esl::Vm* vm = esl::Vm::get();
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    if (!str)
        throw esl::Exception("1st parameter of variable_exist must be a string");

    // int ret = vm->is_register_variable(str->data_get());

    return new esl::GCObject(new esl::IntObject(0));//new esl::IntObject(ret));
}

esl::GCObject* Esl::type_method(const esl::Params& params,
                                esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("type_method take 2 parameters");

    esl::StringObject* type = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* method = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    if (!type)
        throw esl::Exception("1st parameter of type_method must be a string");
    if (!method)
        throw esl::Exception("2nd parameter of type_method must be a string");

    int ret = esl::Squeleton::get()->type_method(type->data_get(),
                                                 method->data_get());

    return new esl::GCObject(new esl::IntObject(ret));
}

esl::GCObject* Esl::type_attribut(const esl::Params& params,
                                  esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("type_attribut take 2 parameters");

    esl::StringObject* type = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* attribut = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    if (!type)
        throw esl::Exception("1st parameter of type_attribut must be a string");
    if (!attribut)
        throw esl::Exception("2nd parameter of type_attribut must be a string");

    int ret = esl::Squeleton::get()->type_attribut(type->data_get(),
                                                   attribut->data_get());

    return new esl::GCObject(new esl::IntObject(ret));
}

esl::GCObject* Esl::object_method(const esl::Params& params,
                                  esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("object_method take 2 parameters");

    esl::Object* obj = dynamic_cast<esl::Object*>(params.get_params(1)->data_get());
    esl::StringObject* method = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    if (!method)
        throw esl::Exception("2nd parameter of object_method must be a string");

    int ret = esl::Squeleton::get()->type_method(obj->type_get(),
                                                 method->data_get());

    return new esl::GCObject(new esl::IntObject(ret));
}

esl::GCObject* Esl::object_attribut(const esl::Params& params,
                                    esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("object_attribut take 2 parameters");

    esl::Object* obj = dynamic_cast<esl::Object*>(params.get_params(1)->data_get());
    esl::StringObject* attribut = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    if (!attribut)
        throw esl::Exception("2nd parameter of object_attribut must be a string");

    int ret = esl::Squeleton::get()->type_attribut(obj->type_get(),
                                                   attribut->data_get());

    return new esl::GCObject(new esl::IntObject(ret));
}

esl::GCObject* Esl::module_function(const esl::Params& params,
                                    esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("module_function take 2 parameters");

    // esl::Vm* vm = esl::Vm::get();
    esl::StringObject* module = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    esl::StringObject* function = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    if (!module)
        throw esl::Exception("1st parameter of module_function must be a string");
    if (!function)
        throw esl::Exception("2nd parameter of module_function must be a string");

    // int ret = vm->module_function(module->data_get(), function->data_get());

    return new esl::GCObject(new esl::IntObject(0));//new esl::IntObject(ret));
}

extern "C"
{
    Esl* get ()
    {
        return new Esl();
    }

    void destroy (Esl* ext)
    {
        delete ext;
    }
}
