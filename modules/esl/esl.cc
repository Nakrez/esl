#include "esl.hh"

void Esl::init ()
{
    register_function("is_function_exist",
                      new esl::Delegate<Esl>(this, &Esl::is_function_exist));
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
