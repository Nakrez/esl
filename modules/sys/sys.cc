#include "sys.hh"
#include "../../lib/type/int-object.hh"

void Sys::init ()
{
    register_function("fork", new esl::Delegate<Sys>(this, &Sys::fork_fun));
}

esl::MemoryObject<esl::Content>* Sys::fork_fun (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::IntObject(fork()));
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
