#include <execute/command.hh>

namespace bytecode
{
    void dump_readable_internal()
    {
        readable_dump(*compile::main_executable);
    }
} // namespace bytecode
