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
} // namespace command

#endif /* !REGISTER_HXX */
