#ifndef COMMAND_HXX
# define COMMAND_HXX

# include <command/command.hh>

namespace command
{
    inline const std::string& Command::descr_get() const
    {
        return descr_;
    }

    inline const std::string& Command::opts_get() const
    {
        return opts_;
    }

    inline const std::string& Command::dep_get() const
    {
        return dep_;
    }

    inline bool Command::enable_get() const
    {
        return enabled_;
    }

    inline void Command::enable_set(bool enable)
    {
        enabled_ = enable;
    }
} // namespace command

#endif /* !COMMAND_HXX */
