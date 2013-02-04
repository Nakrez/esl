#include "int.hh"
#include "string-object.hh"
#include "int-object.hh"
#include <cmath>

esl::Int::Int ()
    : esl::Type ("Int")
{

}

esl::Int::~Int ()
{

}

esl::GCObject* esl::Int::construct (const Params&, Context*)
{
    return new esl::GCObject(new esl::IntObject(0));
}

esl::GCObject* esl::Int::print (const Params& params, Context*)
{
    esl::IntObject* obj = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    std::cout << obj->data_get();

    return new esl::GCObject (new esl::IntObject(0));
}

esl::GCObject* esl::Int::to_string (const Params&, Context*)
{
    return new esl::GCObject (new esl::StringObject("Int"));
}

std::string esl::Int::type_name_get () const
{
    return name_;
}

esl::GCObject* esl::Int::plus_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 + value2));
}

esl::GCObject* esl::Int::minus_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 - value2));
}

esl::GCObject* esl::Int::mul_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 * value2));
}

esl::GCObject* esl::Int::div_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 / value2));
}

esl::GCObject* esl::Int::mod_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 % value2));
}

esl::GCObject* esl::Int::pow_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();
    int powered = pow(value1, value2);

    return new esl::GCObject(new esl::IntObject(powered));
}

esl::GCObject* esl::Int::eq_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 == value2));
}

esl::GCObject* esl::Int::diff_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 != value2));
}

esl::GCObject* esl::Int::gt_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 > value2));
}

esl::GCObject* esl::Int::ge_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 >= value2));
}

esl::GCObject* esl::Int::lt_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 < value2));
}

esl::GCObject* esl::Int::le_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 <= value2));
}

esl::GCObject* esl::Int::and_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 && value2));
}

esl::GCObject* esl::Int::or_op (const Params& params, Context*)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::GCObject(new esl::IntObject(value1 || value2));
}
