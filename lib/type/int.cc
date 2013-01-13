#include "int.hh"
#include "string.hh"
#include "int-object.hh"
#include <cmath>

esl::Int::Int ()
    : esl::Type ("Int")
{

}

esl::Int::~Int ()
{

}

esl::MemoryObject<esl::Content>* esl::Int::print (const Params& params)
{
    esl::IntObject* obj = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    std::cout << obj->data_get();

    return new esl::MemoryObject<esl::Content> (new esl::IntObject(0));
}

esl::MemoryObject<esl::Content>* esl::Int::to_string (const Params&)
{
    return new esl::MemoryObject<esl::Content> (new esl::String("Int"));
}

std::string esl::Int::type_name_get () const
{
    return name_;
}

esl::MemoryObject<esl::Content>* esl::Int::plus_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 + value2));
}

esl::MemoryObject<esl::Content>* esl::Int::minus_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 - value2));
}

esl::MemoryObject<esl::Content>* esl::Int::mul_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 * value2));
}

esl::MemoryObject<esl::Content>* esl::Int::div_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 / value2));
}

esl::MemoryObject<esl::Content>* esl::Int::mod_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 % value2));
}

esl::MemoryObject<esl::Content>* esl::Int::pow_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();
    int powered = pow(value1, value2);

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(powered));
}

esl::MemoryObject<esl::Content>* esl::Int::eq_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 == value2));
}

esl::MemoryObject<esl::Content>* esl::Int::diff_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 != value2));
}

esl::MemoryObject<esl::Content>* esl::Int::gt_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 > value2));
}

esl::MemoryObject<esl::Content>* esl::Int::ge_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 >= value2));
}

esl::MemoryObject<esl::Content>* esl::Int::lt_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 < value2));
}

esl::MemoryObject<esl::Content>* esl::Int::le_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 <= value2));
}

esl::MemoryObject<esl::Content>* esl::Int::and_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 && value2));
}

esl::MemoryObject<esl::Content>* esl::Int::or_op (const Params& params)
{
    esl::IntObject* op1 = dynamic_cast<esl::IntObject*>(params.get_params(1)->data_get());
    esl::IntObject* op2 = dynamic_cast<esl::IntObject*>(params.get_params(2)->data_get());
    int value1 = op1->data_get();
    int value2 = op2->data_get();

    return new esl::MemoryObject<esl::Content>(new esl::IntObject(value1 || value2));
}
