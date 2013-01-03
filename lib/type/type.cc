#include "type.hh"

esl::Type::Type ()
{
    register_method("print",
                    new esl::Method(new esl::Delegate<esl::Type>(this, &esl::Type::print)),
                    PUBLIC);
}

esl::Type::~Type ()
{

}

void esl::Type::register_method (const std::string& name,
                                 esl::Method* method,
                                 Visibility visibility)
{
    if (this->method_.find(name) != this->method_.end())
        this->method_[name].first->decr();

    this->method_[name] = std::pair<Method*, Visibility>(method, visibility);
}
