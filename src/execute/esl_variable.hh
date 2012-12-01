#ifndef ESL_VARIABLE_H_
# define ESL_VARIABLE_H_

enum var_type
{
    T_INT,
    T_STRING,
};

class esl_variable
{
    public:
        esl_variable();
        ~esl_variable();

        void *get_content();
        enum var_type get_type();
        void set_content(void *);
        void set_type(enum var_type);
    private:
        void            *content;
        enum var_type   type;
};

#endif /* !ESL_VARIABLE_H_ */
