#include "array.hh"

void Array::init ()
{
    register_function("create", new esl::Delegate<Array>(this,
                                                          &Array::create));
}

esl::ContentObject* Array::create (esl::Params* params)
{
    esl::ContentObject* ret = new esl::ContentObject(O_ARRAY, nullptr);
    int* size = static_cast<int*> (params->get_params(1)->content_get());
    esl::Array* array = new esl::Array(*size);

    ret->content_set(array);

    return ret;
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
