#include "io.hh"

void Io::init ()
{
    register_function("print", new esl::Delegate<Io>(this, &Io::print));
}

esl::MemoryObject<esl::Content>* Io::print (const esl::Params& params)
{
    for (int i = 0; i < params.count(); ++i)
    {
        esl::Type* obj = nullptr;

        obj = dynamic_cast<esl::Type*> (params.get_params(i + 1)->data_get());

        if (obj)
            obj->print();
        else
            std::cout << "**Unknow**";
    }

    std::cout << std::endl;

    return new esl::MemoryObject<esl::Content> (new esl::Int(0));
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
