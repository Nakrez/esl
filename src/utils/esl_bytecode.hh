#ifndef ESL_BYTECODE_H_
# define ESL_BYTECODE_H_

# include <string>

enum instr
{
    /*
    ** Remove the top of the stack
    */
    POP,

    /*
    ** Duplicate the top of the stack
    */
    DUP_TOP,

    /*
    ** Binary operators take the two top elements in the stack, performe the
    ** operation and push the result on the stack
    */

    /*
    ** Perform an addition
    */
    ARITH_ADD,

    /*
    **
    */

    /*
    ** Store the top of the stack in the variable name
    */
    STORE,

    /*
    ** Push the value of the variable name in the stack
    */
    LOAD,

    /*
    ** Push a constant value in the stack
    **
    ** 1 param : the constant value
    */
    LOAD_CST,

    /*
    **
    */

    /*
    ** Jump at target adress if the top of the stack is true
    ** The top of the stack is POP
    **
    ** 1 param : the target adress
    */

    JUMP_IF_TRUE,

    /*
    ** Jump at target adress if the top of the stack is false
    ** The top of the stack is POP
    **
    ** 1 param : the target adress
    */

    JUMP_IF_FALSE,

    /*
    ** Jump at target adress
    **
    ** 1 param : the target adress
    */
    JUMP

};

const static std::string instr_string[] =
{
    "POP",
    "DUP_TOP",
    "ARITH_ADD",
    "STORE",
    "LOAD",
    "LOAD_CST",
    "JUMP_IF_TRUE",
    "JUMP_IF_FALSE",
    "JUMP"
};

class esl_bytecode
{
    public:
        esl_bytecode(enum instr type, int type_param, void *param);
        ~esl_bytecode();

        enum instr  get_type();
        int         get_type_param();
        void        *get_param();

    private:
        enum instr  type;
        int         type_param;
        void        *param;
};

#endif /* ESL_BYTECODE_H_ */
