#include <command/command.hh>
#include <command/register.hh>

namespace command
{
    Command::Command(const std::string& description,
                     const std::string& options,
                     const std::string& dep)
        : descr_(description)
        , opts_(options)
        , dep_(dep)
        , enabled_(false)
    {
        Register::instance().register_command(*this);
    }

    Command::~Command()
    {}
} // namespace command
