#ifndef EMPTY_STACK_EXCEPTION_HH
# define EMPTY_STACK_EXCEPTION_HH

# include <exception>

namespace esl
{
    class EmptyStackException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Empty Stack !";
            }
    };
}
#endif /* !EMPTY_STACK_EXCEPTION_HH */
