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

            static int gt_int (const int*, const int*);
            static int gt_str (const std::string*, const std::string*);

            static int ge_int (const int*, const int*);
            static int ge_str (const std::string*, const std::string*);

            static int lt_int (const int*, const int*);
            static int lt_str (const std::string*, const std::string*);

            static int le_int (const int*, const int*);
            static int le_str (const std::string*, const std::string*);
    };
}

#endif /* !OPERATION_HH */
