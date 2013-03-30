#ifndef AST_COMMAND_HH
# define AST_COMMAND_HH

# include <global.hh>

# include <command/libcommand.hh>

# include <ast/libast.hh>

namespace ast
{
    REGULAR_COMMAND("-P|--pretty-print",
                    "Pretty print a file (Usefull for internal debug)",
                    "-p|--parse", internal_pretty_print);
} // namespace ast

#endif /* !AST_COMMAND_HH */
