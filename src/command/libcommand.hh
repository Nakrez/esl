#ifndef LIBCOMMAND_HH
# define LIBCOMMAND_HH

# include <command/command.hh>
# include <command/callback-command.hh>

# define REGULAR_COMMAND(Argv, Description, Dep, Callback)                \
    extern void (Callback)();                                             \
    static command::CallbackCommand command_##Callback(Description, Argv, \
                                                       Dep, Callback)
#endif /* !LIBCOMMAND_HH */
