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
    RETURN_STM,

    UNTIL,
    WHILE,

    IMPORT,
    MODULE_CALL,

    IF,

    EXPR,

    ADD,
    MINUS,
    MUL,
    DIV,
    MOD,

    EQ,
    DIFF,
    GT,
    LT,
    GE,
    LE,
    OR,
    AND,

    ID,
    NUMBER,
    STRING
};

const static std::string token_string[] =
{
    "EMPTY",
    "STATEMENTS",
    "LIST",

    "ASSIGNEMENT",
    "FUNCTION_CALL",

    "FUNCTION_DECL",
    "RETURN_STM",
    "UNTIL",
    "WHILE",

    "IMPORT",
    "MODULE_CALL",
    "IF",

    "EXPR",

    "ADD",
    "MINUS",
    "MUL",
    "DIV",
    "MOD",

    "EQ",
    "DIFF",
    "GT",
    "LT",
    "GE",
    "LE",

    "OR",
    "AND",

    "ID",
    "NUMBER",
    "STRING"
};

#endif /* !TOKEN_H_ */
