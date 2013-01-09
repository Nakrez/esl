#ifndef TOKEN_H_
# define TOKEN_H

enum token
{
    EMPTY,
    STATEMENTS,

    LIST,
    LIST_ID,

    ASSIGNEMENT,
    ASSIGNEMENT_ARRAY,

    FUNCTION_CALL,

    FUNCTION_DECL,
    CLASS_DECL,
    METHOD_CALL,

    RETURN_STM,

    UNTIL,
    WHILE,

    IMPORT,
    MODULE_CALL,

    IF,

    ARRAY_AT,
    EXPR,

    ADD,
    MINUS,
    MUL,
    DIV,
    MOD,
    POW,

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
    "LIST_ID",

    "ASSIGNEMENT",
    "ASSIGNEMENT_ARRAY",

    "FUNCTION_CALL",

    "FUNCTION_DECL",
    "CLASS_DECL",
    "METHOD_CALL",

    "RETURN_STM",
    "UNTIL",
    "WHILE",

    "IMPORT",
    "MODULE_CALL",
    "IF",

    "ARRAY_AT",

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
