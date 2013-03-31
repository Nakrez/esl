#ifndef COMPILE_COMMAND_HH
# define COMPILE_COMMAND_HH

# include <command/libcommand.hh>

# include <compile/libcompile.hh>

namespace compile
{
    REGULAR_COMMAND("-c|--compile",
                    "Compile a file into ESL bytecode",
                    "-p|--parse", internal_compile);
} // namespace compile

#endif /* !COMPILE_COMMAND_HH */
