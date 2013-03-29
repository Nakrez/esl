#ifndef COMMAND_HH
# define COMMAND_HH

# include <string>

namespace command
{
    class Command
    {
        public:
            Command(const std::string& description,
                    const std::string& options,
                    const std::string& dep);
            virtual ~Command();

            const std::string& descr_get() const;
            const std::string& opts_get() const;
            const std::string& dep_get() const;

            virtual void execute() = 0;

        protected:
            std::string descr_;
            std::string opts_;
            std::string dep_;
    };
} // namespace command

# include <command/command.hxx>

#endif /* !COMMAND_HH */
