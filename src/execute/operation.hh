#ifndef OPERATION_HH
# define OPERATION_HH

# include <string>

namespace esl
{
    class Operation
    {
        public:
            static int add_int (const int*, const int*);
            static std::string add_str (const std::string*,
                                        const std::string*);

            static int eq_int (const int*, const int*);
            static int eq_str (const std::string*, const std::string*);

            static int diff_int (const int*, const int*);
            static int diff_str (const std::string*, const std::string*);

    };
}

#endif /* !OPERATION_HH */
