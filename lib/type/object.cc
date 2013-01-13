#include "object.hh"

esl::Object::Object (const std::string& type)
    : type_ (type)
{

}

esl::MemContent esl::Object::call_method (const std::string& fun_name,
                                           esl::Context* context,
                                           const esl::Params& params)
{
    return esl::Squeleton::get()->method_get(type_, fun_name)->call(context, params);
}

esl::Function* esl::Object::get_method (const std::string& fun_name)
{
    return esl::Squeleton::get()->method_get(type_, fun_name);
}
