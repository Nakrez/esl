#include "extension.hh"

esl::Extension::Extension ()
{

}

esl::Extension::~Extension ()
{
    for (auto fun : functions_)
        delete fun.second;
}

void esl::Extension::register_function (const std::string& name,
                                        esl::DelegateBase *func)
{
    functions_[name] = func;
}

bool esl::Extension::is_registered (const std::string& name) const
{
    return functions_.find(name) != functions_.end();
}

esl::MemoryObject<esl::Content> *esl::Extension::call (const std::string& name,
                                                       const esl::Params& params)
{
    return functions_.at(name)->Call(params);
}
