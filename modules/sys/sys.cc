#include "sys.hh"

void Sys::init ()
{
    //register_function("print", new esl::Delegate<Io>(this, &Io::print));
}

extern "C"
{
    Sys* get ()
    {
        return new Sys();
    }

    void destroy (Sys* ext)
    {
        delete ext;
    }
}
