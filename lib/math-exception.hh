#ifndef MATH_EXCEPTION_HH
# define MATH_EXCEPTION_HH

# include <exception>

namespace esl
{
    class MathException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Math exception !";
            }

    };
}

#endif /* !MATH_EXCEPTION_HH */
