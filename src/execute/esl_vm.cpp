#include <execute/esl_vm.hh>

esl_vm::esl_vm(std::vector<esl_bytecode *> *code)
{
    this->code = code;
}

esl_vm::~esl_vm()
{

}

void esl_vm::run()
{

}
