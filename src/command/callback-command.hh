/// @date 29/03/2013

#ifndef CALLBACK_COMMAND_HH
# define CALLBACK_COMMAND_HH

# include <string>

# include <command/command.hh>

namespace command
{
    class CallbackCommand : public command::Command
    {
        public:
            CallbackCommand(const std::string& description,
                            const std::string& options,
                            const std::string& dep,
                            void (*callback)());

            virtual ~CallbackCommand();

            virtual void execute() const;

        protected:
            void (*callback_)();
    };
} // namespace command

#endif /* !CALLBACK_COMMAND_HH */
