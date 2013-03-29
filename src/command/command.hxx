#ifndef COMMAND_HXX
# define COMMAND_HXX

# include <command/command.hh>

namespace command
{
    inline const std::string& Command::descr_get() const
    {
        return descr_;
    }

    inline const std::string& Command::dep_get() const
    {
        return dep_;
    }
} // namespace command

#endif /* !COMMAND_HXX */
