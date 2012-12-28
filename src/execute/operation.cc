#include "operation.hh"

int esl::Operation::add_int (const int* a, const int* b)
{
    return *a + *b;
}

std::string esl::Operation::add_str (const std::string* a,
                                     const std::string* b)
{
    return *a + *b;
}

int esl::Operation::eq_int (const int* a, const int* b)
{
    return *a == *b;
}

int esl::Operation::eq_str (const std::string* a, const std::string* b)
{
    return *a == *b;
}
