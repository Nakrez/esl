#include "bytecode.hh"

esl::Bytecode::Bytecode(instr type, Value *param)
{
    this->type_ = type;
    this->param_ = param;
}

esl::Bytecode::~Bytecode()
{
    if (param_)
        delete this->param_;
}

instr esl::Bytecode::get_type()
{
    return this->type_;
}

esl::Value *esl::Bytecode::get_param()
{
    return this->param_;
}

void esl::Bytecode::set_param(esl::Value *param)
{
    this->param_ = param;
}
