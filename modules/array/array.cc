#include "array.hh"

void Array::init ()
{
    register_function("create", new esl::Delegate<Array>(this,
                                                          &Array::create));
}

esl::MemoryObject<esl::Content>* Array::create (const esl::Params& params)
{
    esl::Int* size = static_cast<esl::Int*> (params.get_params(1)->data_get());
    esl::Array* array = new esl::Array(size->data_get());

    return new esl::MemoryObject<esl::Content> (array);
}

extern "C"
{
    Array* get ()
    {
        return new Array();
    }

    void destroy (Array* ext)
    {
        delete ext;
    }
}
