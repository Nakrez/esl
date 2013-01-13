#include "type.hh"

esl::Type::Type (const std::string& name)
    : name_ (name)
{
}

esl::Type::~Type ()
{
}

void esl::Type::init_basics ()
{
    esl::Squeleton* squeleton = esl::Squeleton::get();

    squeleton->register_type(name_, this);
}

void esl::Type::init ()
{
    init_basics ();
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

esl::MemoryObject<esl::Content>* esl::Type::pow_op (const Params&)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide ^ operator");

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
