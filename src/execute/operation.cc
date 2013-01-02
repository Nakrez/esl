#include "operation.hh"

int esl::Operation::add_int (int a, int b)
{
    return a + b;
}

std::string esl::Operation::add_str (const std::string& a,
                                     const std::string& b)
{
    return a + b;
}

int esl::Operation::eq_int (int a, int b)
{
    return a == b;
}

int esl::Operation::eq_str (const std::string& a, const std::string& b)
{
    return a == b;
}

int esl::Operation::diff_int (int a, int b)
{
    return a != b;
}

int esl::Operation::diff_str (const std::string& a, const std::string& b)
{
    return a != b;
}

int esl::Operation::gt_int (int a, int b)
{
    return a > b;
}

int esl::Operation::gt_str (const std::string& a, const std::string& b)
{
    return a > b;
}

int esl::Operation::ge_int (int a, int b)
{
    return a >= b;
}

int esl::Operation::ge_str (const std::string& a, const std::string& b)
{
    return a >= b;
}

int esl::Operation::lt_int (int a, int b)
{
    return a < b;
}

int esl::Operation::lt_str (const std::string& a, const std::string& b)
{
    return a < b;
}

int esl::Operation::le_int (int a, int b)
{
    return a <= b;
}

int esl::Operation::le_str (const std::string& a, const std::string& b)
{
    return a <= b;
}