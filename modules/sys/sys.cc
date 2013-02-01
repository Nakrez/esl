#include "sys.hh"
#include "../../lib/type/int-object.hh"
#include "../../lib/type/string-object.hh"

void Sys::init ()
{
    register_function("fork", new esl::Delegate<Sys>(this, &Sys::fork_fun));
    register_function("vfork", new esl::Delegate<Sys>(this, &Sys::fork_fun));
    register_function("exit", new esl::Delegate<Sys>(this, &Sys::exit_fun));
    register_function("chdir", new esl::Delegate<Sys>(this, &Sys::chdir_fun));
    register_function("getcwd", new esl::Delegate<Sys>(this,
                                                       &Sys::getcwd_fun));
    register_function("getenv", new esl::Delegate<Sys>(this,
                                                       &Sys::getenv_fun));
    register_function("setenv", new esl::Delegate<Sys>(this,
                                                       &Sys::setenv_fun));
}

esl::MemoryObject<esl::Content>* Sys::fork_fun (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::IntObject(fork()));
}

esl::MemoryObject<esl::Content>* Sys::vfork_fun (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::IntObject(vfork()));
}

esl::MemoryObject<esl::Content>* Sys::chdir_fun (const esl::Params& params)
{
    if (params.count() < 1)
        throw esl::Exception("chdir takes 1 parameter");

    esl::StringObject* new_path = nullptr;

    new_path = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    const char* path = new_path->data_get().c_str();

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(chdir(path)));
}

esl::MemoryObject<esl::Content>* Sys::getenv_fun (const esl::Params& params)
{
    if (params.count() < 1)
        throw esl::Exception("getenv takes 1 parameter");

    esl::StringObject* var = nullptr;

    var = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());

    const char *var_content = getenv(var->data_get().c_str());
    if (var_content == nullptr)
        return new esl::MemoryObject<esl::Content> (new esl::StringObject());

    return new esl::MemoryObject<esl::Content> (new esl::StringObject(var_content));
}

esl::MemoryObject<esl::Content>* Sys::setenv_fun (const esl::Params& params)
{
    if (params.count() < 2)
        throw esl::Exception("setenv takes 2 parameters");

    esl::StringObject* var1 = nullptr;
    esl::StringObject* var2 = nullptr;

    var1 = dynamic_cast<esl::StringObject*>(params.get_params(1)->data_get());
    var2 = dynamic_cast<esl::StringObject*>(params.get_params(2)->data_get());

    int ret = !setenv(var1->data_get().c_str(), var2->data_get().c_str(), 1);

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(ret));
}

esl::MemoryObject<esl::Content>* Sys::getcwd_fun (const esl::Params&)
{
    std::string dir = getcwd(NULL, 0);

    return new esl::MemoryObject<esl::Content> (new esl::StringObject(dir));
}

esl::MemoryObject<esl::Content>* Sys::exit_fun (const esl::Params& params)
{
    if (params.count() == 0)
        exit(0);

    esl::IntObject* return_value = nullptr;

    return_value = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());

    if (return_value)
        exit(return_value->data_get());
    else
        throw esl::Exception("First parameter of exit must be an integer");

    // Never reached
    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
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
