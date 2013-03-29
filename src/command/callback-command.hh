#ifndef CALLBACK_COMMAND_HH
# define CALLBACK_COMMAND_HH

# include <command/command.hh>

namespace command
{
    class CallbackCommand : public Command
    {
        public:
            CallbackCommand(const std::string& description,
                            const std::string& dep,
                            const std::string& options,
                            void (*callback)());

            virtual ~CallbackCommand();

            virtual void execute();
    };
} // namespace command

#endif /* !CALLBACK_COMMAND_HH */
