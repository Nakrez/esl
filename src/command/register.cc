#include <command/register.hh>

namespace command
{
    Register& Register::instance()
    {
        static Register instance;
        return instance;
    }

    void Register::register_command(const Command& command)
    {
        if (commands_.find(command.opts_get()) == commands_.end())
            commands_.insert(make_pair(command.opts_get(), &command));
        else
            error_ << misc::Error::OTHER
                   << "Commands : " << command.opts_get()
                   << " already registered" << std::endl;
    }

    void Register::parse_args(int argc, char **argv)
    {
        int i = 1;

        program_name = argv[0];

        for ( ; i < argc && argv[i][0] == '-'; ++i)
        {
            // FIXME IMPROVE
            for (auto elem : commands_)
            {
                if (match(elem.first, argv[i]))
                {
                    enable_command(elem.first);
                    break;
                }
            }
        }

        if (i < argc)
            main_filename = argv[i];
    }

    bool Register::match(const std::string& pattern, const std::string& str)
    {
        // FIXME IMPROVE
        if (pattern.size() > 2 && pattern[2] == '|')
        {
            std::string first(pattern.substr(0, 2));
            std::string second(pattern.substr(3, pattern.size() - 2));

            return str == first || str == second;
        }
        else
            return pattern == str;
    }

    void Register::enable_command(const std::string& str)
    {
        // FIXME resolve dependency
        execution_order_.push_back(commands_.at(str));
    }

    void Register::execute()
    {
        for (auto com : execution_order_)
            com->execute();
    }
} // namespace command
