#include "squeleton.hh"
#include "type.hh"

namespace esl
{
    Squeleton* esl::Squeleton::instance_ = nullptr;

    Squeleton::Squeleton ()
    {}

    Squeleton::~Squeleton ()
    {
        for (auto type : declared_type_)
            delete type.second;

        for (auto methods : object_methods_)
        {
            for (auto method : methods.second)
                method.second.first->decr();
        }
    }

    Squeleton& esl::Squeleton::get ()
    {
        static Squeleton instance_;
        return instance_;
    }

    void Squeleton::register_type (const std::string& name, Type* ptr)
    {
        // Error type already exists
        if (this->declared_type_.find(name) != this->declared_type_.end())
            throw Exception("Redeclaration of type " + name);

        this->declared_type_[name] = ptr;
    }

    inline void Squeleton::type_existance (const std::string& name)
    {
        if (this->declared_type_.find(name) == this->declared_type_.end())
            throw Exception ("unknow type " + name);
    }

    Function* esl::Squeleton::method_get(const std::string& type,
            const std::string& name)
    {
        type_existance (type);

        if (this->object_methods_.at(type).find(name) ==
                this->object_methods_.at(type).end())
            throw Exception ("unknow method " + name + " in type " + type);

        return this->object_methods_.at(type).at(name).first->data_get();
    }

    const Attributs& esl::Squeleton::attributs_get (const std::string& type)
    {
        type_existance (type);

        return object_attributs_[type];
    }

    bool Squeleton::has_attribut(const std::string& type)
    {
        type_existance (type);

        return !object_attributs_[type].empty();
    }

    bool Squeleton::type_exist(const std::string& type)
    {
        return declared_type_.find(type) != declared_type_.end();
    }

    bool Squeleton::type_attribut(const std::string& type,
            const std::string& attribut)
    {
        if (!type_exist(type))
            return 0;

        return object_attributs_[type].find(attribut) !=
            object_attributs_[type].end();
    }

    bool Squeleton::type_method(const std::string& type,
            const std::string& method)
    {
        if (!type_exist(type))
            return 0;

        return object_methods_[type].find(method) !=
            object_methods_[type].end();
    }

    void Squeleton::register_method (const std::string& type,
            const std::string& name,
            Function* fun)
    {
        MemoryObject<esl::Function>* fun_obj = nullptr;

        fun_obj = new MemoryObject<esl::Function>(fun);

        if (this->object_methods_.find(type) !=
                this->object_methods_.end() &&
                this->object_methods_.at(type).find(name) !=
                this->object_methods_.at(type).end())
            this->object_methods_[type][name].first->decr();

        this->object_methods_[type][name] = Method(fun_obj, PUBLIC);
    }


    void Squeleton::register_attribut(const std::string& type,
                                      const std::string& name)
    {
        this->object_attributs_[type][name] = PUBLIC;
    }

    void Squeleton::inherit(const std::string& type,
                            const std::string& inherit)
    {
        for (auto method : object_methods_[inherit])
        {
            method.second.first->incr();

            if (method.first != "construct")
            {
                if (this->object_methods_.at(type).find(method.first) !=
                        this->object_methods_.at(type).end())
                    object_methods_.at(type).at(method.first).first->decr();

                object_methods_[type][method.first] = Method(method.second);
            }
            else // Register super method
            {
                if (this->object_methods_.at(type).find("__super_" + inherit) !=
                        this->object_methods_.at(type).end())
                    object_methods_.at(type).at("__super_" + inherit).first->decr();

                object_methods_[type]["__super_" + inherit] = Method(method.second);
            }
        }

        this->object_attributs_[type].insert(this->object_attributs_[inherit].begin(),
                this->object_attributs_[inherit].end());
    }
} // namespace esl
