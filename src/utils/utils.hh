#ifndef UTILS_H_
# define UTILS_H_

# include <string>
# include <sstream>

namespace esl
{
    class Utils
    {
        public:
            static int atoi(const std::string &);
            static std::string itoa(int);
    };
}

#endif /* UTILS_H_ */
