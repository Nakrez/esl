/// @date 29/03/2013
#ifndef PARSER_COMMAND_HH
# define PARSER_COMMAND_HH

# include <global.hh>

# include <command/libcommand.hh>

# include <parser/libparser.hh>

namespace parser
{
    REGULAR_COMMAND("-p|--parse", "Parse a file", "", parse_file);
} // namespace parser

#endif /* !PARSER_COMMAND_HH */
