#include "utils.hh"

int esl::Utils::atoi(const std::string &s)
{
    int numb;
    std::istringstream(s) >> numb;
    return numb;
}

std::string esl::Utils::itoa(int number)
{
    std::stringstream str;

    str << number;

    return str.str();
}
