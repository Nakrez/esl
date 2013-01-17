#include "stack-module.hh"

void ArrayModule::init ()
{
    // Register type Array
    (new esl::Array())->init();
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
