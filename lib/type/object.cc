#include "object.hh"
#include "int-object.hh"

esl::Object::Object (const std::string& type)
    : type_ (type)
{
    if (esl::Squeleton::get().has_attribut(type))
        register_attribut(esl::Squeleton::get().attributs_get(type));
}

esl::Object::~Object ()
{
    for (auto attribut : attributs_)
    {
        attribut.second.first->decr();
    }
}

esl::GCObject* esl::Object::call_method (const std::string& fun_name,
                                           esl::Context* context,
                                           const esl::Params& params)
{
    return esl::Squeleton::get().method_get(type_, fun_name)->call(context, params);
}

esl::Function* esl::Object::get_method (const std::string& fun_name)
{
    return esl::Squeleton::get().method_get(type_, fun_name);
}

void esl::Object::register_attribut (const std::unordered_map<std::string, Visibility>& attr)
{
    for (auto attribut : attr)
    {
        esl::IntObject* object = new esl::IntObject(0);
        esl::GCObject* default_value = new GCObject(object);
        attributs_[attribut.first] = std::pair<esl::GCObject*,
                                               Visibility>(default_value,
                                                           attribut.second);
    }
}

esl::GCObject* esl::Object::attribut_get (const std::string& attr_name)
{
    if (attributs_.find(attr_name) == attributs_.end())
        throw esl::Exception("No attribut " +
                             attr_name + " found on class " + type_);

    return attributs_.at(attr_name).first;
}
void esl::Object::update_attribut (const std::string& attr_name,
                                   esl::GCObject* value)
{
    if (attributs_.find(attr_name) == attributs_.end())
        throw esl::Exception("No attribut " +
                             attr_name + " found on class " + type_);

    attributs_.at(attr_name).first->decr();

    attributs_[attr_name] = std::pair<esl::GCObject*,
                                      Visibility>(value,
                                                  attributs_.at(attr_name).second);
}

const std::string& esl::Object::type_get() const
{
    return type_;
}
