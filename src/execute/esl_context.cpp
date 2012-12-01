#include <execute/esl_context.hh>

esl_context::esl_context()
{
    this->variables = new std::unordered_map<std::string, esl_variable *>;
    this->functions = new std::unordered_map<std::string, int>;
    this->pc = 0;
}

esl_context::~esl_context()
{
    delete this->variables;
    delete this->functions;
}

esl_variable *esl_context::get_variable(std::string var_name)
{
    return this->variables->at(var_name);
}

int esl_context::get_function(std::string fun_name)
{
    return this->functions->at(fun_name);
}

int esl_context::get_pc()
{
    return this->pc;
}

void esl_context::set_variable(const std::string &var_name, esl_variable *value)
{
    (*this->variables)[var_name] = value;
}

void esl_context::set_function(const std::string &fun_name, int value)
{
    (*this->functions)[fun_name] = value;
}

void esl_context::set_pc(int pc)
{
    this->pc = pc;
}

void esl_context::incr_pc()
{
    ++(this->pc);
}
