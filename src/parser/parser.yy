%require "2.4"
%skeleton "lalr1.cc"
%code requires
{

#include <string>
#include <list>

#include <ast/all.hh>

class Driver;
}

%define parser_class_name "eslxx_parser"
%debug
%defines
/* No conflict accepted */

/*
%expect 0
%expect-rr 0
*/

/* Better errors */
%error-verbose

/* Enable location tracking */
%locations
%parse-param { Driver& driver }
%lex-param   { Driver& driver }
%pure-parser

%union
{
    std::string *sval;
    int ival;
    ast::Ast *ast;
    std::list<ast::Ast *> *lval;
}

%code
{
#include <parser/driver.hh>
}

%token  END       0         "end_of_file"
        TOK_EQ              "="
        TOK_DOT             "."
        TOK_SEPARATOR       ";"
        TOK_PLUS            "+"
        TOK_MINUS           "-"
        TOK_MUL             "*"
        TOK_DIV             "/"
        TOK_MOD             "%"
        TOK_POW             "^"
        TOK_BIN_EQ          "=="
        TOK_DIFF            "!="
        TOK_GT              ">"
        TOK_GE              ">="
        TOK_LT              "<"
        TOK_LE              "<="
        TOK_AND             "&&"
        TOK_OR              "||"
        TOK_DOUBLEP         ":"
        TOK_ARROW           "->"
        TOK_NEW             "new"
        TOK_PAROPEN         "("
        TOK_PARCLOSE        ")"
        TOK_COMA            ","
        TOK_IF              "if"
        TOK_THEN            "then"
        TOK_ELSE            "else"
        TOK_ELIF            "elif"
        TOK_END             "end"
        TOK_IMPORT          "import"
        TOK_INCLUDE         "include"
        TOK_FUNCTION        "function"
        TOK_RETURN          "return"
        TOK_FOR             "for"
        TOK_DO              "do"
        TOK_WHILE           "while"
        TOK_UNTIL           "until"
        TOK_BRACKET_OP      "["
        TOK_BRACKET_CL      "]"
        TOK_CLASS           "class"
        TOK_PUBLIC          "public"
        TOK_PRIVATE         "private"
        TOK_PROTECTED       "protected"

%token <sval>
        TOK_ID              "identifier"
        TOK_STRING          "string"
        TOK_MOD_ID          "mod_id"

%token <ival>
        TOK_DIGIT           "digit"

%type <ast> instr expr functions esl_command fun_call
%type <ast> rule_while rule_until rule_if do_group else_group
%type <ast> class_decl class_component object_call_list

%type <lval> compound_list id_list param_list arrays class_components

%right "="
%left "||" "&&"
%left "==" "!=" "<" ">" "<=" ">="
%left "+" "-"
%left "*" "/" "%"
%left "^"
%left "[" ")" "->" "("


%%

input   :
        | input instr
        ;

instr   :
        expr
        |functions
        |class_decl
        |esl_command
        |"import" "string"
        |"include" "string"
        ;

class_decl:
          "class" "identifier" class_components "end"
          |"class" "identifier" ":" "(" param_list ")" class_components "end"
          ;

visibility :
           | "public"
           | "private"
           | "protected"
           ;

class_component:
                visibility functions
                |visibility "identifier"
                |visibility "identifier" "=" expr
                ;

class_components:
                class_component
                |class_components class_component
                ;

compound_list   :
                "return" expr
                |expr
                |esl_command
                | compound_list expr
                | compound_list esl_command
                | compound_list "return" expr
                ;

object_call_list:
                expr "->" "identifier"
                |expr "->" fun_call
                |object_call_list "->" "identifier"
                |object_call_list "->" fun_call
                ;

param_list      :
                "identifier"
                | param_list "," "identifier"
                ;

id_list         :
                expr
                | id_list "," expr
                ;

fun_call        :
                "identifier" "(" ")"
                |"identifier" "(" id_list ")"
                ;

functions       :
                "function" "identifier" "(" ")" compound_list "end"
                |"function" "identifier" "(" param_list ")" compound_list "end"
                ;

arrays          :
                 "[" expr "]"
                | arrays "[" expr "]"
                ;

expr            :
                expr "+" expr
                |expr "-" expr
                |expr "*" expr
                |expr "/" expr
                |expr "%" expr
                |expr "^" expr
                |expr "==" expr
                |expr "!=" expr
                |expr ">" expr
                |expr ">=" expr
                |expr "<" expr
                |expr "<=" expr
                |expr "&&" expr
                |expr "||" expr
                |"(" expr ")"
                |"digit"
                |"string"
                |"identifier"
                |fun_call
                |object_call_list
                |"new" fun_call
                |"identifier" "=" expr
                | object_call_list "=" expr
                |"mod_id" "." fun_call
                |"identifier" arrays "=" expr
                |"identifier" arrays
                ;

esl_command     :
                rule_if
                |rule_until
                |rule_while
                ;

rule_if         :
                "if" expr "then" compound_list else_group "end"
                |"if" expr "then" compound_list "end"
                ;

else_group      :
                "else" compound_list
                |"elif" expr "then" compound_list
                |"elif" expr "then" compound_list else_group
                ;

rule_while      :
                "while" expr do_group
                ;

rule_until      :
                "until" expr do_group
                ;

do_group        :
                "do" compound_list "end"
                ;
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                               const std::string& m)
{
    driver.error(l, m);
}
