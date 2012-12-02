#include <utils/esl_bytecode.hh>

esl_bytecode::esl_bytecode(enum instr type, esl_value *param)
{
    this->type = type;
    this->param = param;
}

esl_bytecode::~esl_bytecode()
{
    if (param)
        delete this->param;
}

enum instr esl_bytecode::get_type()
{
    return this->type;
}

esl_value *esl_bytecode::get_param()
{
    return this->param;
}

void esl_bytecode::set_param(esl_value *param)
{
    this->param = param;
}
