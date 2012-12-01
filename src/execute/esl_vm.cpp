#include <execute/esl_vm.hh>

esl_vm::esl_vm(std::vector<esl_bytecode *> *code)
{
    this->code = code;

    /* Initialise the first instruction to the first one */
    this->pc = 0;
}

esl_vm::~esl_vm()
{

}

void esl_vm::run()
{

}
