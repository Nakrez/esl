%require "2.4"
%skeleton "lalr1.cc"
%code requires
{

#include <string>
#include <list>

#include "../utils/ast.hh"

class Driver;
}

%define parser_class_name "eslxx_parser"
%debug
%defines
/* No conflict accepted */
%expect 0
%expect-rr 0

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
    esl::Ast *ast;
    std::list<esl::Ast *> *lval;
}

%code
{
#include "driver.hh"
}

%token END       0 "end_of_file"
%token TOK_NEWLINE "\n" TOK_EQ "=" TOK_DOT "."
%token TOK_PLUS "+" TOK_MINUS "-" TOK_MUL "*" TOK_DIV "/" TOK_MOD "%"
%token TOK_BIN_EQ "==" TOK_DIFF "!=" TOK_GT ">" TOK_GE ">="
%token TOK_LT "<" TOK_LE "<="
%token TOK_AND "&&" TOK_OR "||"
%token TOK_PAROPEN "(" TOK_PARCLOSE ")" TOK_COMA ","
%token TOK_IF "if" TOK_THEN "then" TOK_ELSE "else" TOK_ELIF "elif"
%token TOK_END "end" TOK_IMPORT "import" TOK_INCLUDE "include"
%token TOK_FUNCTION "function" TOK_RETURN "return"
%token TOK_FOR "for" TOK_DO "do" TOK_WHILE "while" TOK_UNTIL "until"
%token TOK_BRACKET_OP "[" TOK_BRACKET_CL "]"

%token <sval> TOK_ID "identifier"  TOK_STRING "string"
%token <ival> TOK_DIGIT "digit"

%type <ast> instr expr functions esl_command fun_call
%type <ast> rule_while rule_until rule_if do_group else_group

%type <lval> compound_list id_list param_list

%right "="
%left "||" "&&"
%left "==" "!=" "<" ">" "<=" ">="
%left "+" "-"
%left "*" "/" "%"

%%

input   :
        |input instr { if ($2) driver.ast()->add($2); }
        ;

instr   :
        expr "\n" { $$ = $1; }
        |functions "\n" { $$ = $1; }
        |esl_command "\n" { $$ = $1; }
        |"\n" { $$ = nullptr; }
        |"import" "string" "\n" { $$ = new esl::Ast(IMPORT, $2); }
        |"include" "string" "\n"
        |error "\n" { $$ = nullptr; }
        ;

compound_list   :
                expr "\n" { $$ = new std::list<esl::Ast *>;
                                    $$->push_back($1); }
                |"return" expr "\n"
                        {
                          $$ = new std::list<esl::Ast*>;
                          esl::Ast* tmp = new esl::Ast(RETURN_STM);
                          tmp->add($2);
                          $$->push_back(tmp);
                        }
                |esl_command "\n"  { $$ = new std::list<esl::Ast *>;
                                    $$->push_back($1); }
                | compound_list expr "\n"
                                    { $$ = $1;
                                    $$->push_back($2); }
                | compound_list esl_command "\n"
                                    { $$ = $1;
                                    $$->push_back($2); }
                ;

param_list         :
                "identifier"
                             { $$ = new std::list<esl::Ast *>;
                               $$->push_back(new esl::Ast(ID, $1));
                             }
                |"identifier" "\n"
                             { $$ = new std::list<esl::Ast *>;
                               $$->push_back(new esl::Ast(ID, $1));
                             }
                | param_list "," "identifier"
                             { $$ = $1;
                               $$->push_back(new esl::Ast(ID, $3));
                             }
                | param_list "," "identifier" "\n"
                             { $$ = $1;
                               $$->push_back(new esl::Ast(ID, $3));
                             }
                ;


id_list         :
                expr
                             { $$ = new std::list<esl::Ast *>;
                               $$->push_back($1);
                             }
                |expr "\n"
                             { $$ = new std::list<esl::Ast *>;
                               $$->push_back($1);
                             }
                | id_list "," expr
                             { $$ = $1;
                               $$->push_back($3);
                             }
                | id_list "," expr "\n"
                             { $$ = $1;
                               $$->push_back($3);
                             }
                ;

fun_call        :
                "identifier" "(" ")" { $$ = new esl::Ast(FUNCTION_CALL, $1); }
                |"identifier" "(" id_list ")"
                                      {
                                        $$ = new esl::Ast(FUNCTION_CALL, $1);
                                        $$->add(esl::Ast::ast_from_list($3));
                                        $$->get_fson()->set_token(LIST);
                                      }
                ;
functions       :
                "function" "identifier" "(" ")" "\n" compound_list "end"
                                        {
                                          $$ = new esl::Ast(FUNCTION_DECL, $2);
                                          $$->add(new esl::Ast(EMPTY));
                                          $$->add(esl::Ast::ast_from_list($6));
                                        }
                |"function" "identifier" "(" param_list ")" "\n" compound_list "end"
                                        {
                                          $$ = new esl::Ast(FUNCTION_DECL, $2);
                                          $$->add(esl::Ast::ast_from_list($4));
                                          $$->get_fson()->set_token(LIST_ID);
                                          $$->add(esl::Ast::ast_from_list($7));
                                        }
                ;
expr            :
                expr "+" expr
                                {
                                    $$ = new esl::Ast(ADD);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "-" expr
                                {
                                    $$ = new esl::Ast(MINUS);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "*" expr
                                {
                                    $$ = new esl::Ast(MUL);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "/" expr
                                {
                                    $$ = new esl::Ast(DIV);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "%" expr
                                {
                                    $$ = new esl::Ast(MOD);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "==" expr
                                {
                                    $$ = new esl::Ast(EQ);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "!=" expr
                                {
                                    $$ = new esl::Ast(DIFF);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr ">" expr
                                {
                                    $$ = new esl::Ast(GT);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr ">=" expr
                                {
                                    $$ = new esl::Ast(GE);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "<" expr
                                {
                                    $$ = new esl::Ast(LT);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "<=" expr
                                {
                                    $$ = new esl::Ast(LE);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "&&" expr
                                {
                                    $$ = new esl::Ast(AND);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "||" expr
                                {
                                    $$ = new esl::Ast(OR);
                                    $$->add($1);
                                    $$->add($3);
                                }

                |"(" expr ")"   { $$ = $2; }
                |"digit" { $$ = new esl::Ast(NUMBER, $1); }
                |"string" { $$ = new esl::Ast(STRING, $1); }
                |"identifier" { $$ = new esl::Ast(ID, $1); }
                |fun_call { $$ = $1; }
                |"identifier" "=" expr {
                                         $$ = new esl::Ast(ASSIGNEMENT);
                                         $$->add(new esl::Ast(ID, $1));
                                         $$->add($3);
                                       }
                |"identifier" "." fun_call
                                         {
                                            $$ = new esl::Ast(MODULE_CALL, $1);
                                            $$->add($3);
                                         }

                ;

esl_command     :
                rule_if { $$ = $1; }
                |rule_until { $$ = $1; }
                |rule_while { $$ = $1; }
                ;

rule_if         :
                "if" expr "then" "\n" compound_list else_group "end"
                                                    {
                                                      $$ = new esl::Ast(IF);
                                                      $$->add($2);
                                                      $$->add(esl::Ast::ast_from_list($5));
                                                      $$->add($6);
                                                    }

                |"if" expr "then" "\n" compound_list "end"
                                                    {
                                                      $$ = new esl::Ast(IF);
                                                      $$->add($2);
                                                      $$->add(esl::Ast::ast_from_list($5));
                                                    }
                ;

else_group      :
                "else" "\n" compound_list { $$ = esl::Ast::ast_from_list($3); }
                |"elif" expr "then" "\n" compound_list
                                                {
                                                  $$ = new esl::Ast(IF);
                                                  $$->add($2);
                                                  $$->add(esl::Ast::ast_from_list($5));
                                                }
                |"elif" expr "then" "\n" compound_list else_group
                                                {
                                                  $$ = new esl::Ast(IF);
                                                  $$->add($2);
                                                  $$->add(esl::Ast::ast_from_list($5));
                                                  $$->add($6);
                                                }
                ;

rule_while      :
                "while" expr do_group {
                                                $$ = new esl::Ast(WHILE);
                                                $$->add($2);
                                                $$->add($3);
                                              }
                ;

rule_until      :
                "until" expr do_group {
                                                $$ = new esl::Ast(UNTIL);
                                                $$->add($2);
                                                $$->add($3);
                                              }
                ;

do_group        :
                "do" "\n" compound_list "end" {
                                                $$ = esl::Ast::ast_from_list($3);
                                              }
                ;
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                               const std::string& m)
{
    driver.error(l, m);
}
