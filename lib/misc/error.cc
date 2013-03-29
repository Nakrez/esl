#include <misc/error.hh>

namespace misc
{
    Error::Error()
        : error_code_(Error::NONE)
        , msg_()
    {}

    Error::Error(const Error& err)
        : error_code_(err.error_code_get())
        , msg_(err.msg_get())
    {

    }

    Error::~Error()
    {}

    Error& Error::operator=(const Error& err)
    {
        error_code_ = err.error_code_;
        msg_ << err.msg_;

        return *this;
    }

    Error& Error::operator<<(ecode error_code)
    {
        if (error_code_ == Error::NONE
            || error_code_ > error_code)
            error_code_ = error_code;

        return *this;
    }

    Error& Error::operator<<(const std::string& msg)
    {
        msg_ << msg;

        return *this;
    }

    Error& Error::operator<<(std::ostream& (*msg) (std::ostream&))
    {
        msg_ << msg;

        return *this;
    }

    std::string Error::msg_get() const
    {
        return msg_.str();
    }

    Error::ecode Error::error_code_get() const
    {
        return error_code_;
    }

    void Error::exit_on_error()
    {
        if (error_code_ != Error::NONE)
        {
            std::cerr << msg_;
            throw *this;
        }
    }

    std::ostream& operator<<(std::ostream& ostr, const Error& error)
    {
        ostr << error.msg_get();

        return ostr;
    }
} // namespace misc
