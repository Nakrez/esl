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
    BIN_ADD,

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
    */
    LOAD_CST,

    /*
    **
    */

    /*
    ** Jump at adress target if the top of the stack is true
    ** The top of the stack is POP
    */

    JUMP_IF_TRUE,

    /*
    ** Jump at adress target if the top of the stack is false
    ** The top of the stack is POP
    */

    JUMP_IF_FALSE,

    /*
    ** Jump at adress target
    */
    JUMP

};

const static std::string instr_string[] =
{
    "POP",
    "DUP_TOP",
    "BIN_ADD",
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
        esl_bytecode(enum instr type);
        ~esl_bytecode();

    private:
        enum instr type;
};

#endif /* ESL_BYTECODE_H_ */
