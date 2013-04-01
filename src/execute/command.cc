#include <execute/command.hh>

namespace execute
{
    void dump_readable_internal()
    {
        readable_dump(*compile::main_executable);
    }

    void execute_internal()
    {
        execute(*compile::main_executable).exit_on_error();
    }
} // namespace execute
