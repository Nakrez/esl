#ifndef ESL_VALUE_H_
# define ESL_VALUE_H_

# include <string>

enum value
{
    V_EMPTY,
    V_INT,
    V_STRING
};

class esl_value
{
    public:
        esl_value();
        esl_value(enum value, void *);
        ~esl_value();

        void *get_value();
        enum value get_type();
        void set_value(void *);
        void set_type(enum value);

    private:
        enum value  type;
        void        *value;
};

#endif /* !ESL_VALUE_H_ */
