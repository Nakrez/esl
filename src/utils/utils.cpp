#include <utils/utils.hh>

int utils::atoi(const std::string &s)
{
    int numb;
    std::istringstream(s) >> numb;
    return numb;
}
