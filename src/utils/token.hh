#ifndef TOKEN_H_
# define TOKEN_H

enum token
{
    EMPTY,
    STATEMENTS,
    LIST,

    ASSIGNEMENT,
    FUNCTION_CALL,

    FUNCTION_DECL,
    UNTIL,
    WHILE,

    IF,

    ADD,
    MINUS,
    MUL,
    DIV,
    MOD,

    ID,
    NUMBER,
    STRING
};

const static std::string token_string[] =
{
    "EMPTY",
    "STATEMENTS",

    "ASSIGNEMENT",
    "FUNCTION_CALL",

    "FUNCTION_DECL",
    "UNTIL",
    "WHILE",

    "IF",

    "ADD",
    "MINUS",
    "MUL",
    "DIV",
    "MOD",

    "ID",
    "NUMBER",
    "STRING"
};

#endif /* !TOKEN_H_ */
