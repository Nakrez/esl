/// @file src/utils/bytecode.hh
/// @brief Def of all instructions supported + class Bytecode which contains
//         a bytecode instruction (with param)
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 29/11/2012

#ifndef ESL_BYTECODE_H_
# define ESL_BYTECODE_H_

# include <string>
# include <iostream>

enum instr
{
    /// Does nothing
    NOP,

    /// POP Tos of the stack (TOS)
    POP,

    /// TOS + TOS1
    OP_ADD,

    /// TOS - TOS1
    OP_MINUS,

    /// TOS * TOS1
    OP_MUL,

    /// TOS / TOS1
    OP_DIV,

    /// TOS % TOS1
    OP_MOD,

    /// TOS ^ TOS1
    OP_POW,

    /// TOS == TOS1
    OP_EQ,

    /// TOS != TOS1
    OP_DIFF,

    /// TOS > TOS1
    OP_GT,

    /// TOS >= TOS1
    OP_GE,

    /// TOS < TOS1
    OP_LT,

    /// TOS <= TOS1
    OP_LE,

    /// TOS && TOS1
    OP_AND,

    /// TOS || TOS1
    OP_OR,

    /// TOS[TOS1]
    OP_BRACKET,

    /// Instanciate arg1
    OP_NEW,

    /*
    ** Store the top of the stack in the variable name
    **
    ** Don't perfrom POP
    */
    STORE,

    /*
    ** TOS = TOS1
    **
    ** POP TOS not TOS1
    */
    STORE_STK,

    STORE_ATTR,

    /// Push the value of the variable name in the stack
    LOAD,

    /// Push an int in the stack
    LOAD_INT,

    /// Push a string in the stack
    LOAD_STR,

    /// Push an attribut from TOS
    LOAD_ATTR,

    /// Open a dynamic module
    OPEN,

    /// Push a module on the stack
    MODULE,

    /// Call TOS.arg1
    CALL_MODULE,

    /// Call arg1
    CALL_FUNCTION,

    /// Call TOS->arg1
    CALL_METHOD,

    START_CLASS,
    END_CLASS,
    MAKE_ATTRIBUT,
    INHERIT,

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

    /// Make a function return. If TOS then return TOS
    RETURN,

    /// Declaration of a function
    MAKE_FUNCTION,

    /// Push a delimiter on stack (for function params)
    DELIM
};

namespace compile
{
    class Bytecode
    {
        public:
            /// @brief Constructor of a bytecode instruction without param
            /// @param type The type of the instruction
            Bytecode (instr type);

            /// @brief Constructor of a bytecode instruction with param
            /// @param type The type of the instruction
            /// @param param The parameter of the instruction
            Bytecode (instr type, int param);

            /// @brief Destructor
            ~Bytecode ();

            /// @brief Get the type of the instruction
            /// @return The type of the instruction
            instr get_type () const;

            /// @brief Get the param of the instruction
            /// @return The value of the param (-1 if there is no parameter)
            int get_param () const;

            /// @brief Set the parameter of the instruction
            /// @param param The parameter you want to set for the instruction
            void set_param (int param);

        private:
            /// @brief The type of the instruction
            enum instr type_;

            /// @brief The parameter of the instruction (-1 if there is no one)
            int param_;
    };
} // namespace compile

std::ostream& operator<< (std::ostream& os, const compile::Bytecode& instr);

#endif /* ESL_BYTECODE_H_ */
