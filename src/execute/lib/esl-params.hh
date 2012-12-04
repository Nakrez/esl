#ifndef ESL_PARAMS_HH
# define ESL_PARAMS_HH

# include <vector>

class EslParams
{
public:
    EslParams ();
    ~EslParams ();

    bool empty () const;
    int count () const;
    EslValue *get(int) const;

private:
    std::vector<EslValue *> params_;
};

#endif /* !ESL_PARAMS_HH */
