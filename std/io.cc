#include "io.hh"

void Io::init ()
{
    register_function("print", new esl::Delegate<Io>(this, &Io::print));
}

esl::ContentObject* Io::print (esl::Params* params)
{
    for (int i = 0; i < params->count(); ++i)
    {
        if (params->get_params(i + 1)->type_get() == O_INT)
            std::cout << *((int*)(params->get_params(i + 1)->content_get()))
                      << std::endl;
        else
            std::cout << "nil" << std::endl;
    }

    return new esl::ContentObject(O_NIL, nullptr);
}

extern "C"
{
    Io* get ()
    {
        return new Io();
    }

    void destroy (Io* ext)
    {
        delete ext;
    }
}
