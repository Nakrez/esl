#include "utils.hh"

int esl::Utils::atoi(const std::string &s)
{
    int numb;
    std::istringstream(s) >> numb;
    return numb;
}
