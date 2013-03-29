#include <command/register.hh>

namespace command
{
    Register& Register::instance()
    {
        static Register instance;
        return instance;
    }
} // namespace command
