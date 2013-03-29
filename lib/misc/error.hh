#ifndef ERROR_HH
# define ERROR_HH

# include <string>
# include <iostream>
# include <sstream>

namespace misc
{
    class Error
    {
        public:
            enum ecode
            {
                NONE = 0,
                SCAN = 1,
                PARSE = 2,
                COMPILE = 3,
                EXEC = 4,
                OTHER = 5
            };

            Error();
            Error(const Error& err);
            ~Error();

            Error& operator=(const Error& err);

            Error& operator<<(ecode error_code);
            Error& operator<<(const std::string& msg);
            Error& operator<<(std::ostream& (*msg) (std::ostream&));

            std::string msg_get() const;
            Error::ecode error_code_get() const;

            void exit_on_error();

        private:
            ecode error_code_;
            std::stringstream msg_;
    };

    std::ostream& operator<<(std::ostream& ostr, const Error& error);
} // namespace misc

#endif /* !ERROR_HH */
