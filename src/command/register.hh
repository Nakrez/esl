#ifndef REGISTER_HH
# define REGISTER_HH

namespace command
{
    class Register
    {
        Register(const Register&) = delete;
        Register& operator=(const Register&) = delete;

        public:
            static Register& instance();

        private:
            Register() = default;
    };
} // namespace command

#endif /* !REGISTER_HH */
