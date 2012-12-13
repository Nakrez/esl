#ifndef ESL_BYTECODE_H_
# define ESL_BYTECODE_H_

# include <string>
# include <iostream>

# include "../../lib/value.hh"

enum instr
{
    NOP,
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
    ARITH_MINUS,
    ARITH_MUL,
    ARITH_DIV,
    ARITH_MOD,

    BOOL_EQ,
    BOOL_DIFF,
    BOOL_GT,
    BOOL_GE,
    BOOL_LT,
    BOOL_LE,

    BOOL_AND,
    BOOL_OR,
    /*
    **
    */

    /*
    ** Store the top of the stack in the variable name
    **
    ** Don't perfrom POP
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
    JUMP,

    RETURN,

    MAKE_FUNCTION,

    CALL_FUNCTION,

    /*
    ** Print everything on the stack
    */
    PRINT
};

const static std::string instr_string[] =
{
    "NOP",
    "POP",
    "DUP_TOP",

    "ARITH_ADD",
    "ARITH_MINUS",
    "ARITH_MUL",
    "ARITH_DIV",
    "ARITH_MOD",

    "BOOL_EQ",
    "BOOL_DIFF",
    "BOOL_GT",
    "BOOL_GE",
    "BOOL_LT",
    "BOOL_LE",

    "BOOL_AND",
    "BOOL_OR",

    "STORE",
    "LOAD",
    "LOAD_CST",
    "JUMP_IF_TRUE",
    "JUMP_IF_FALSE",
    "JUMP",
    "RETURN",
    "MAKE_FUNCTION",
    "CALL_FUNCTION",
    "PRINT"
};

namespace esl
{
    class Bytecode
    {
        public:
            Bytecode(instr type, Value* param);
            ~Bytecode();

            instr get_type();
            Value *get_param();
            void set_param(Value *);

        private:
            enum instr  type_;
            Value   *param_;
    };
}
#endif /* ESL_BYTECODE_H_ */
