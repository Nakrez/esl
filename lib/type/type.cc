#include "type.hh"

esl::Type::Type ()
{
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

esl::MemoryObject<esl::Content>* esl::Type::minus_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide - operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::mul_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide * operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::div_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide / operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::mod_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide % operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::and_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide && (and) operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::or_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide || (or) operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::eq_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide == operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::diff_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide != (<>) operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::gt_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide > operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::ge_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide >= operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::lt_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide < operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::le_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide <= operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::bracket_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide [] operator");

    return new MemoryObject<esl::Content>(nullptr);
}

esl::MemoryObject<esl::Content>* esl::Type::call_method (const std::string& name,
                                                         const esl::Params& params)
{

    if (name == "print")
        return this->print(params);
    if (name.find("operator") != std::string::npos)
    {
        if (name == "operator+")
            return this->plus_op(params);
        if ("operator-" == name)
            return this->minus_op(params);
        if ("operator*" == name)
            return this->mul_op(params);
        if ("operator/" == name)
            return this->div_op(params);
        if ("operator%" == name)
            return this->mod_op(params);
        if ("operator==" == name)
            return this->eq_op(params);
        if ("operator!=" == name)
            return this->diff_op(params);
        if ("operator>" == name)
            return this->gt_op(params);
        if ("operator>=" == name)
            return this->ge_op(params);
        if ("operator<" == name)
            return this->lt_op(params);
        if ("operator<=" == name)
            return this->le_op(params);
        if ("operator&&" == name)
            return this->and_op(params);
        if ("operator||" == name)
            return this->and_op(params);
        if ("operator[]" == name)
            return this->bracket_op(params);
    }

    if (this->method_.find(name) == this->method_.end())
        throw esl::Exception("Method "
                             + name
                             + " not found in " + type_name_get());

    return this->method_[name].first->data_get()->Call(params);
}
