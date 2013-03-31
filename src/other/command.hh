#ifndef OTHER_COMMAND_HH
# define OTHER_COMMAND_HH

# include <iostream>

# include <global.hh>

# include <command/register.hh>
# include <command/libcommand.hh>

namespace other
{
    REGULAR_COMMAND("-h|--help",
                    "Display the help of ESL command line utilisation",
                    "", help);

    REGULAR_COMMAND("usage",
                    "Display the usage of ESL binary",
                    "", usage);

    REGULAR_COMMAND("-v|--version",
                    "Display the current version of ESL binary",
                    "", version);
} // namespace other

#endif /* !OTHER_COMMAND_HH */
