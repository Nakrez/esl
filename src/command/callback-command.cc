# include <command/callback-command.hh>

namespace command
{
    CallbackCommand::CallbackCommand(const std::string& description,
                                     const std::string& options,
                                     const std::string& dep,
                                     void (*callback)())
        : Command(description, options, dep)
        , callback_(callback)
    {}

    CallbackCommand::~CallbackCommand()
    {}

    void CallbackCommand::execute() const
    {
        callback_();
    }
} // namespace command
