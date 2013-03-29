#ifndef REGISTER_HH
# define REGISTER_HH

# include <command/command.hh>

namespace command
{
    class Register
    {
        Register(const Register&) = delete;
        Register& operator=(const Register&) = delete;

        public:
            static Register& instance();
            void register_command(const Command& command);

        private:
            Register() = default;
    };
} // namespace command

#endif /* !REGISTER_HH */
