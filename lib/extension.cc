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

esl::ContentObject* esl::Extension::call (const std::string& name,
                                          esl::Params* params)
{
    return functions_.at(name)->Call(params);
}
