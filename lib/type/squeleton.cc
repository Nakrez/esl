#include "squeleton.hh"
#include "type.hh"

esl::Squeleton* esl::Squeleton::instance_ = nullptr;

esl::Squeleton::Squeleton ()
{

}

esl::Squeleton::~Squeleton ()
{
    for (auto type : declared_type_)
        delete type.second;

    for (auto methods : object_methods_)
    {
        for (auto method : methods.second)
        {
            delete method.second.first;
        }
    }
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
    if (this->declared_type_.find(name) == this->declared_type_.end())
        throw esl::Exception ("unknow type " + name);
}

esl::Function* esl::Squeleton::method_get(const std::string& type,
                                          const std::string& name)
{
    type_existance (type);

    if (this->object_methods_.at(type).find(name) ==
        this->object_methods_.at(type).end())
        throw esl::Exception ("unknow method " + name + " in type " + type);

    return this->object_methods_.at(type).at(name).first;
}


void esl::Squeleton::register_method (const std::string& type,
                                      const std::string& name,
                                      Function* fun)
{
    try
    {
        delete this->object_methods_[type][name].first;
    }
    catch (...)
    {

    }

    this->object_methods_[type][name] = Method(fun, PUBLIC);
}


void esl::Squeleton::register_attribut (const std::string& type,
                                        const std::string& name)
{
    try
    {
        delete this->object_methods_[type][name].first;
    }
    catch (...)
    {

    }

    this->object_attributs_[type][name] = PUBLIC;
}
