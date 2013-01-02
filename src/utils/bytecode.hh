#ifndef ESL_BYTECODE_H_
# define ESL_BYTECODE_H_

# include <string>
# include <iostream>

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
    STORE_STK,
    /*
    ** Push the value of the variable name in the stack
    */
    LOAD,

    LOAD_INT,
    LOAD_STR,

    ARRAY_VAL,

    OPEN,
    MODULE,
    CALL_MODULE,
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

    DELIM
};

namespace esl
{
    class Bytecode
    {
        public:
            Bytecode (instr type);
            Bytecode (instr type, int param);
            ~Bytecode ();

            instr get_type () const;
            int get_param () const;
            void set_param (int);

        private:
            enum instr type_;
            int param_;
    };
}

std::ostream& operator<< (std::ostream& os, const esl::Bytecode& instr);

#endif /* ESL_BYTECODE_H_ */
