#include <execute/executable.hh>

namespace execute
{
    Executable::Executable()
    {}

    Executable::~Executable()
    {
        for (auto instr : code_)
            delete instr;
    }
} // namespace execute
