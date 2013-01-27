#include "esl.hh"

void Esl::init ()
{
    //register_function("print", new esl::Delegate<Esl>(this, &Io::print));
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
