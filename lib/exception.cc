#include "exception.hh"

esl::Exception::Exception (const std::string& str)
    : msg_ (str)
{

}

const std::string& esl::Exception::message () const
{
    return msg_;
}
