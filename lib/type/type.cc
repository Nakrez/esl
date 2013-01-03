#include "type.hh"

esl::Type::Type ()
{
    register_method("print",
                    new esl::Method(new esl::Delegate<esl::Type>(this, &esl::Type::print)),
                    PUBLIC);

    register_method("operator+",
                    new esl::Method(new esl::Delegate<esl::Type>(this, &esl::Type::plus_op)),
                    PUBLIC);
}

esl::Type::~Type ()
{
    for (auto method : method_)
        method.second.first->decr();
}

void esl::Type::register_method (const std::string& name,
                                 esl::Method* method,
                                 Visibility visibility)
{
    if (this->method_.find(name) != this->method_.end())
        this->method_[name].first->decr();

    this->method_[name] = std::pair<Method*, Visibility>(method, visibility);
}

esl::MemoryObject<esl::Content>* esl::Type::plus_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide + operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::call_method (const std::string& name,
                                                         const esl::Params& params)
{
    if (this->method_.find(name) == this->method_.end())
        throw esl::Exception("Method "
                             + name
                             + " not found in " + type_name_get());

    return this->method_[name].first->data_get()->Call(params);
}
