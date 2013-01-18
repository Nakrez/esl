#include "stack-module.hh"

void StackModule::init ()
{
    // Register type Array
    (new esl::Stack())->init();
}

extern "C"
{
    StackModule* get ()
    {
        return new StackModule();
    }

    void destroy (StackModule* ext)
    {
        delete ext;
    }
}
