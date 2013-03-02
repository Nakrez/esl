#include "io.hh"

void Io::init ()
{
    (new esl::File)->init();

    register_function("print", new esl::Delegate<Io>(this, &Io::print));
    register_function("print_newline",
                      new esl::Delegate<Io>(this, &Io::print_newline));
}

esl::MemoryObject<esl::Content>* Io::print_core (const esl::Params& params)
{
    for (int i = 0; i < params.count(); ++i)
    {
        esl::Object* obj = nullptr;
        esl::Params print_params;
        esl::MemoryObject<esl::Content>* mem = nullptr;

        obj = dynamic_cast<esl::Object*> (params.get_params(i + 1)->data_get());

        if (obj)
        {
            mem = new esl::MemoryObject<esl::Content>(obj);
            print_params.params_set(mem);

            esl::Vm::get()->external_call(obj->get_method("print"),
                                          print_params);
            esl::Vm::get()->pop();

            mem->free();
        }
        else
            std::cout << "**Unknow**";

    }

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* Io::print (const esl::Params& params)
{
    esl::MemoryObject<esl::Content>* ret = this->print_core(params);

    std::cout << std::flush;

    return ret;
}

esl::MemoryObject<esl::Content>* Io::print_newline (const esl::Params& params)
{
    esl::MemoryObject<esl::Content>* ret = this->print_core(params);

    std::cout << std::endl;

    return ret;
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
