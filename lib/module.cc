#include "module.hh"

esl::Module::Module (const std::string& path, const std::string& name)
    : path_ (path)
    , name_ (name)
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

bool esl::Module::is_registered(const std::string& name) const
{
    return ext_->is_registered(name);
}

const std::string& esl::Module::name_get () const
{
    return name_;
}

esl::GCObject* esl::Module::call(const std::string& name,
                                 const esl::Params& params,
                                 Context* context)
{
    return ext_->call(name, params, context);
}
