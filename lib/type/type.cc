#include "type.hh"
#include "int-object.hh"
#include "string-object.hh"
#include "object.hh"

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

    squeleton->register_method (name_, "construct",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::construct)));
    squeleton->register_method (name_, "type",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::type)));
    squeleton->register_method (name_, "print",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::print)));
    squeleton->register_method (name_, "tostring",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::to_string)));
    squeleton->register_method (name_, "operator+",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::plus_op)));
    squeleton->register_method (name_, "operator-",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::minus_op)));
    squeleton->register_method (name_, "operator*",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::mul_op)));
    squeleton->register_method (name_, "operator/",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::div_op)));
    squeleton->register_method (name_, "operator%",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::mod_op)));
    squeleton->register_method (name_, "operator^",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::pow_op)));
    squeleton->register_method (name_, "operator==",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::eq_op)));
    squeleton->register_method (name_, "operator!=",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::diff_op)));
    squeleton->register_method (name_, "operator>",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::gt_op)));
    squeleton->register_method (name_, "operator>=",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::ge_op)));
    squeleton->register_method (name_, "operator<",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::lt_op)));
    squeleton->register_method (name_, "operator<=",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::le_op)));
    squeleton->register_method (name_, "operator&&",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::and_op)));
    squeleton->register_method (name_, "operator||",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::or_op)));
    squeleton->register_method (name_, "operator[]",
                                new Function(new Delegate<esl::Type>(this,
                                                                     &esl::Type::bracket_op)));
}

void esl::Type::inherit (const std::string& type)
{
    esl::Squeleton::get()->inherit(name_, type);
}

void esl::Type::init ()
{
    init_basics ();
}

std::string esl::Type::type_name_get() const
{
    return name_;
}

esl::MemoryObject<esl::Content>* esl::Type::type (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content>(new esl::StringObject(name_));
}

esl::MemoryObject<esl::Content>* esl::Type::construct (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content>(new esl::Object(name_));
}

esl::MemoryObject<esl::Content>* esl::Type::print (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content>(new esl::IntObject(0));
}
esl::MemoryObject<esl::Content>* esl::Type::to_string (const esl::Params&)
{
    return new esl::MemoryObject<esl::Content>(new esl::IntObject(0));
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
