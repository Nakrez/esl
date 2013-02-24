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
    ast::Instr *ast_instr;
    ast::Exp *ast_exp;
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

%type <ast_exp> expr

%type <ast_instr> instr
                  esl_command
                  rule_if

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
        expr { $$ = $1; }
        |functions
        |class_decl
        |esl_command { $$ = $1; }
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
                compound
                | compound_list compound
                ;
compound:
        "return" expr
        | expr
        | esl_command
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
                '-' expr
                {
                  $$ = new ast::OpExp(@2,
                                      new ast::IntExp(@1, 0),
                                      ast::OpExp::Operator::add,
                                      $2);
                }
                | expr "+" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::add, $3);
                }
                | expr "-" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::min, $3);
                }
                | expr "*" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::tim, $3);
                }
                | expr "/" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::div, $3);
                }
                | expr "%" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::mod, $3);
                }
                | expr "^" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::pow, $3);
                }
                | expr "==" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::eq, $3);
                }
                | expr "!=" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::neq, $3);
                }
                | expr ">" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::gt, $3);
                }
                | expr ">=" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::ge, $3);
                }
                | expr "<" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::lt, $3);
                }
                | expr "<=" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::le, $3);
                }
                | expr "&&" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::and_, $3);
                }
                | expr "||" expr
                {
                  $$ = new ast::OpExp(@3, $1, ast::OpExp::Operator::or_, $3);
                }
                |"(" expr ")" { $$ = $2; }
                |"digit" { $$ = new ast::IntExp(@1, $1); }
                |"string" { $$ = new ast::StringExp(@1, *$1); }
                |"identifier" { $$ = new ast::IdExp(@1, *$1); }
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
                rule_if { $$ = $1; }
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

