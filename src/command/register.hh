/// @date 29/03/2013

#ifndef REGISTER_HH
# define REGISTER_HH

# include <iostream>
# include <list>
# include <string>
# include <map>

# include <global.hh>

# include <misc/error.hh>

# include <command/command.hh>

namespace command
{
    class Register
    {
        Register(const Register&) = delete;
        Register& operator=(const Register&) = delete;

        public:
            static Register& instance();
            void register_command(Command& command);

            misc::Error error_get() const;

            int number_enable_command() const;
            void parse_args(int argc, char **argv);

            void enable_command(const std::string& str);
            void execute();
            void resolve_dependency(const std::string& str);

        private:
            bool match(const std::string& pattern, const std::string& str);

        private:
            Register() = default;
            misc::Error error_;

            std::map<std::string, Command*> commands_;
            std::list<Command*> execution_order_;
    };
} // namespace command

# include <command/register.hxx>

#endif /* !REGISTER_HH */
