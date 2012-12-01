#ifndef ESL_STACK_OBJ_H_
# define ESL_STACK_OBJ_H_

# include <execute/esl_value.hh>
# include <execute/esl_context.hh>

enum stack_type
{
    S_EMPTY,
    S_VAL,
    S_CONTEXT
};

class esl_stack_obj
{
    public:
        esl_stack_obj();
        esl_stack_obj(void *, enum stack_type);
        ~esl_stack_obj();

        void *get_object();
        enum stack_type get_type();
        void set_object(void *);
        void set_type(enum stack_type);

    private:
        enum stack_type type;
        void            *object;
};

#endif /* !ESL_STACK_OBJ_H_ */
