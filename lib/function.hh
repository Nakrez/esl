#ifndef ESL_FUNCTION_HH
# define ESL_FUNCTION_HH

# include <vm/core/esl-callback.hh>

class EslFunction
{
public:
    EslFunction ();
    ~EslFunction ();

    std::string get_name() const;
    EslObject *call(EslParams *);

private:
    std::string name_;
    EslCallback *callback_;
};

#endif /* !ESL_FUNCTION_HH */
