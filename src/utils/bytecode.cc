#include "bytecode.hh"

const static std::string instr_string[] =
{
    "NOP",
    "POP",

    "OP_ADD",
    "OP_MINUS",
    "OP_MUL",
    "OP_DIV",
    "OP_MOD",
    "OP_POW",

    "OP_EQ",
    "OP_DIFF",
    "OP_GT",
    "OP_GE",
    "OP_LT",
    "OP_LE",

    "OP_AND",
    "OP_OR",

    "OP_BRACKET",

    "OP_NEW",

    "STORE",
    "STORE_STK",
    "STORE_ATTR",

    "LOAD",
    "LOAD_INT",
    "LOAD_STR",
    "LOAD_ATTR",

    "OPEN",
    "MODULE",

    "CALL_MODULE",
    "CALL_FUNCTION",
    "CALL_METHOD",

    "START_CLASS",
    "END_CLASS",
    "MAKE_ATTRIBUT",

    "JUMP_IF_TRUE",
    "JUMP_IF_FALSE",
    "JUMP",
    "RETURN",
    "MAKE_FUNCTION",
    "DELIM"
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
