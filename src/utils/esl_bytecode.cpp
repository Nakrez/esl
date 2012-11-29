#include <utils/esl_bytecode.hh>

esl_bytecode::esl_bytecode(enum instr type, int type_param, void *param)
{
    this->type = type;
    this->type_param = type_param;
    this->param = param;
}

esl_bytecode::~esl_bytecode()
{
    if (param)
    {
        if (type_param == 1)
            delete (int *)param;
        else
            delete (std::string *)param;
    }
}

enum instr esl_bytecode::get_type()
{
    return this->type;
}

int esl_bytecode::get_type_param()
{
    return this->type_param;
}

void *esl_bytecode::get_param()
{
    return this->param;
}

void esl_bytecode::set_param(void *param)
{
    this->param = param;
}

void esl_bytecode::set_type(enum instr type)
{
    this->type = type;
}
