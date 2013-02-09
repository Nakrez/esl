#include "esl.hh"

void Esl::init ()
{
    register_function("function_exist",
                      new esl::Delegate<Esl>(this, &Esl::is_function_exist));
    register_function("module_exist",
                      new esl::Delegate<Esl>(this, &Esl::is_module_exist));
    register_function("variable_exist",
                      new esl::Delegate<Esl>(this, &Esl::is_variable_exist));
}

esl::GCObject* Esl::is_function_exist(const esl::Params& params,
                                      esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("is_function_exist take 1 parameter");

    esl::Vm* vm = esl::Vm::get();
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    if (!str)
        throw esl::Exception("1st parameter of is_function_exist must be a string");

    int ret = vm->is_register_function(str->data_get());

    return new esl::GCObject(new esl::IntObject(ret));
}

esl::GCObject* Esl::is_module_exist(const esl::Params& params,
                                    esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("is_module_exist take 1 parameter");

    esl::Vm* vm = esl::Vm::get();
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    if (!str)
        throw esl::Exception("1st parameter of is_module_exist must be a string");

    int ret = vm->is_register_module(str->data_get());

    return new esl::GCObject(new esl::IntObject(ret));
}

esl::GCObject* Esl::is_variable_exist(const esl::Params& params,
                                      esl::Context*)
{
    if (params.count() < 1)
        throw esl::Exception("is_variable_exist take 1 parameter");

    esl::Vm* vm = esl::Vm::get();
    esl::StringObject* str = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    if (!str)
        throw esl::Exception("1st parameter of is_variable_exist must be a string");

    int ret = vm->is_register_variable(str->data_get());

    return new esl::GCObject(new esl::IntObject(ret));
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
