#ifndef ERROR_HH
# define ERROR_HH

namespace misc
{
    class Error
    {
        public:
            enum error_code
            {
                SCAN = 1
                PARSE = 2,
                COMPILE = 3,
                EXEC = 4,
                OTHER = 5
            };

            Error();
            ~Error();

            error& operator<<(int error_code);

        private:
            int error_code_;
    };
} // namespace misc

#endif /* !ERROR_HH */
