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

esl::GCObject* esl::Type::type (const esl::Params&, Context*)
{
    return new esl::GCObject(new esl::StringObject(name_));
}

esl::GCObject* esl::Type::construct (const esl::Params&, Context*)
{
    return new esl::GCObject(new esl::Object(name_));
}

esl::GCObject* esl::Type::print (const esl::Params&, Context*)
{
    return new esl::GCObject(new esl::IntObject(0));
}
esl::GCObject* esl::Type::to_string (const esl::Params&, Context*)
{
    return new esl::GCObject(new esl::IntObject(0));
}

esl::GCObject* esl::Type::plus_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide + operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::minus_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide - operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::mul_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide * operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::div_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide / operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::mod_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide % operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::pow_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide ^ operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::and_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide && (and) operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::or_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide || (or) operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::eq_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide == operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::diff_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide != (<>) operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::gt_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide > operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::ge_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide >= operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::lt_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide < operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::le_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide <= operator");

    return new esl::GCObject(nullptr);
}

esl::GCObject* esl::Type::bracket_op (const Params&, Context*)
{
    throw esl::Exception("Type "
                         + type_name_get()
                         + " does not provide [] operator");

    return new esl::GCObject(nullptr);
}
