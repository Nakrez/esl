#include "bytecode.hh"

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
    "SOTRE_STK",

    "LOAD",
    "LOAD_INT",
    "LOAD_STR",

    "ARRAY_VAL",

    "OPEN",
    "MODULE",
    "CALL_MODULE",
    "JUMP_IF_TRUE",
    "JUMP_IF_FALSE",
    "JUMP",
    "RETURN",
    "MAKE_FUNCTION",
    "CALL_FUNCTION",
};

esl::Bytecode::Bytecode (instr type)
{
    this->type_ = type;
    this->param_ = -1;
}

esl::Bytecode::Bytecode (instr type, int param)
{
    this->type_ = type;
    this->param_ = param;
    if (type == STORE && param == -1)
        std::cout << "FDSF" << std::endl;
}

esl::Bytecode::~Bytecode ()
{
}

instr esl::Bytecode::get_type () const
{
    return this->type_;
}

int esl::Bytecode::get_param () const
{
    return this->param_;
}

void esl::Bytecode::set_param (int param)
{
    this->param_ = param;
}

std::ostream& operator<< (std::ostream& os, const esl::Bytecode& instr)
{
    os << instr_string[instr.get_type()] << " " << instr.get_param()
       << std::endl;

    return os;
}
