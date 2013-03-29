#include "io.hh"

void Io::init ()
{
    (new esl::File)->init();

    register_function("print", new esl::Delegate<Io>(this, &Io::print));
    register_function("print_newline",
                      new esl::Delegate<Io>(this, &Io::print_newline));
    register_function("read_line",
                      new esl::Delegate<Io>(this, &Io::read_line));
}

esl::GCObject* Io::print_core (const esl::Params& params)
{
    for (int i = 0; i < params.count(); ++i)
    {
        esl::Object* obj = nullptr;
        esl::Params print_params;
        esl::GCObject* mem = nullptr;

        obj = dynamic_cast<esl::Object*> (params.get_params(i + 1)->data_get());

        if (obj)
        {
            mem = new esl::GCObject(obj);
            print_params.params_set(mem);

            /*esl::Vm::get()->external_call(obj->get_method("print"),
                                          print_params);
            esl::Vm::get()->pop();*/

            mem->free();
        }
        else
            std::cout << "**Unknow**";

    }

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* Io::print (const esl::Params& params, esl::Context*)
{
    esl::GCObject* ret = this->print_core(params);

    std::cout << std::flush;

    return ret;
}

esl::GCObject* Io::read_line (const esl::Params& params, esl::Context*)
{
    esl::GCObject* ret = this->print_core(params);
    std::string input;

    getline(std::cin, input);

    ret = new esl::GCObject(new esl::StringObject(input));

    return ret;
}

esl::GCObject* Io::print_newline (const esl::Params& params, esl::Context*)
{
    esl::GCObject* ret = this->print_core(params);

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
