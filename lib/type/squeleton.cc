#include "squeleton.hh"

esl::Squeleton* esl::Squeleton::instance_ = nullptr;

esl::Squeleton::Squeleton ()
{

}

esl::Squeleton::~Squeleton ()
{

}

esl::Squeleton* esl::Squeleton::get ()
{
    if (!instance_)
        instance_ = new Squeleton ();

    return instance_;
}

void esl::Squeleton::free ()
{
    if (instance_)
    {
        delete instance_;
        instance_ = nullptr;
    }
}

void esl::Squeleton::register_type (const std::string& name, Type* ptr)
{
    // Error type already exists
    if (this->declared_type_.find(name) != this->declared_type_.end())
        throw esl::Exception("Redeclaration of type " + name);

    this->declared_type_[name] = ptr;
}

inline void esl::Squeleton::type_existance (const std::string& name)
{
    if (this->object_methods_.find(name) == this->object_methods_.end() &&
        this->object_attributs_.find(name) == this->object_attributs_.end())
        throw esl::Exception ("unknow type " + name);
}

esl::Function* esl::Squeleton::method_get(const std::string& type,
                                          const std::string& name)
{
    type_existance (type);

    if (this->object_methods_.at(type).find(name) ==
        this->object_methods_.at(type).end())
        throw esl::Exception ("unknow method " + name + " int type " + type);

    return this->object_methods_.at(type).at(name).first;
}


void esl::Squeleton::register_method (const std::string& type,
                                      const std::string& name,
                                      Function* fun)
{
    this->object_methods_.at(type)[name] = Method(fun, PUBLIC);
}
