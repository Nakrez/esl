#include <command/register.hh>

namespace command
{
    Register& Register::instance()
    {
        static Register instance;
        return instance;
    }

    void Register::register_command(const Command& command)
    {
        // FIXME
    }
} // namespace command
