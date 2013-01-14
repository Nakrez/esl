#include "array-module.hh"

void ArrayModule::init ()
{
    // Register type Array
    (new esl::Array())->init();

    // Will be replace with constructor
    register_function("create", new esl::Delegate<ArrayModule>(this,
                                                          &ArrayModule::create));
}

esl::MemoryObject<esl::Content>* ArrayModule::create (const esl::Params& params)
{
    esl::IntObject* size = static_cast<esl::IntObject*> (params.get_params(1)->data_get());
    esl::ArrayObject* array = new esl::ArrayObject(size->data_get());

    return new esl::MemoryObject<esl::Content>(array);
}

extern "C"
{
    ArrayModule* get ()
    {
        return new ArrayModule();
    }

    void destroy (ArrayModule* ext)
    {
        delete ext;
    }
}
