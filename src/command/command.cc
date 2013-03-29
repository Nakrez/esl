#include <command/command.hh>

namespace command
{
    Command::Command(const std::string& description,
                     const std::string& dep)
        : descr_(description)
        , dep_(dep)
    {}
} // namespace command
