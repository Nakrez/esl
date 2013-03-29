#include <command/command.hh>

namespace command
{
    Command::Command(const std::string& description,
                     const std::string& options,
                     const std::string& dep)
        : descr_(description)
        , opts_(options)
        , dep_(dep)
    {}

    Command::~Command()
    {}
} // namespace command
