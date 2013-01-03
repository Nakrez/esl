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
        esl::Params print_params;
        esl::MemoryObject<esl::Content>* mem = nullptr;

        obj = dynamic_cast<esl::Type*> (params.get_params(i + 1)->data_get());



        if (obj)
        {
            mem = new esl::MemoryObject<esl::Content>(obj);
            print_params.params_set(mem);

            obj->print(print_params)->decr();

            mem->free();
        }
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
