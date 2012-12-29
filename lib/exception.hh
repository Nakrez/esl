#ifndef MATH_EXCEPTION_HH
# define MATH_EXCEPTION_HH

# include <string>

namespace esl
{
    class Exception
    {
        public:
            Exception (const std::string& str);
            const std::string& message() const;

        private:
            std::string msg_;
    };
}

#endif /* !MATH_EXCEPTION_HH */
