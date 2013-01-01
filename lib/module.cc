#include "module.hh"

esl::Module::Module (const std::string& path)
    : path_ (path)
{
    ext_ = nullptr;
    destroy_module_ = nullptr;
}

esl::Module::~Module ()
{
    if (destroy_module_ && ext_)
        destroy_module_(ext_);

    if (this->lib_)
        dlclose(this->lib_);
}

void esl::Module::load ()
{
    EGet get_module = nullptr;

    this->lib_ = dlopen(this->path_.c_str(), RTLD_LAZY);

    if (!this->lib_)
    {
        std::cerr << "Cannot load esl module: " << dlerror() << std::endl;
        exit(5);
    }

    get_module = (EGet)(dlsym(lib_, "get"));
    const char* err = dlerror();

    if (err)
    {
        std::cerr << "Cannot load esl module: " << err << std::endl;
        exit(5);
    }

    destroy_module_ = (EDestroy)(dlsym(lib_, "destroy"));
    err = dlerror();

    if (err)
    {
        std::cerr << "Cannot load esl module: " << err << std::endl;
        exit(5);
    }

    ext_ = get_module();
    ext_->init();
}

esl::MemoryObject<esl::Content>* esl::Module::call(const std::string& name,
                                                   const esl::Params& params)
{
    return ext_->call(name, params);
}
