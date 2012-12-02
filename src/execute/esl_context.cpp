#include <execute/esl_context.hh>

esl_context::esl_context()
{
    this->variables = new std::unordered_map<std::string, esl_value *>;
    this->functions = new std::unordered_map<std::string, size_t>;
    this->pc = 0;
}

esl_context::~esl_context()
{
    delete this->variables;
    delete this->functions;
}

esl_value *esl_context::get_variable(std::string var_name)
{
    return this->variables->at(var_name);
}

size_t esl_context::get_function(std::string fun_name)
{
    return this->functions->at(fun_name);
}

size_t esl_context::get_pc()
{
    return this->pc;
}

void esl_context::set_variable(const std::string &var_name, esl_value *value)
{
    (*this->variables)[var_name] = value;
}

void esl_context::set_function(const std::string &fun_name, size_t value)
{
    (*this->functions)[fun_name] = value;
}

void esl_context::set_pc(size_t pc)
{
    this->pc = pc;
}

void esl_context::incr_pc(size_t pc)
{
    this->pc += pc;
}
