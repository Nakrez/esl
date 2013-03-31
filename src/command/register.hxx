#ifndef REGISTER_HXX
# define REGISTER_HXX

# include <command/register.hh>

namespace command
{
    inline misc::Error Register::error_get() const
    {
        return error_;
    }

    inline int Register::number_enable_command() const
    {
        return execution_order_.size();
    }

    inline const std::map<std::string, Command*>&
    Register::commands_get() const
    {
        return commands_;
    }
} // namespace command

#endif /* !REGISTER_HXX */
