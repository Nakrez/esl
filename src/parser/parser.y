%skeleton "lalr1.cc"
%code requires
{
#include <string>
#include <list>

#include <utils/esl_ast.hh>

class eslxx_driver;
}

%define parser_class_name "eslxx_parser"
%debug

/* No conflict accepted */
%expect 0

/* Better errors */
%error-verbose

/* Enable location tracking */
%locations
%parse-param { eslxx_driver& driver }
%lex-param   { eslxx_driver& driver }
%pure-parser

%union
{
    std::string             *sval;
    esl_ast                 *ast;
    std::list<esl_ast *>    *lval;
}

%code
{
#include <parser/eslxx_driver.hh>
}

%token END       0 "end_of_file"
%token TOK_NEWLINE "\n" TOK_EQ "="
%token TOK_PLUS "+" TOK_MINUS "-" TOK_MUL "*" TOK_DIV "/" TOK_MOD "%"
%token TOK_PAROPEN "(" TOK_PARCLOSE ")" TOK_COMA ","
%token TOK_IF "if" TOK_THEN "then" TOK_ELSE "else" TOK_ELIF "elif"
%token TOK_END "end"
%token TOK_FUNCTION "function"
%token TOK_FOR "for" TOK_DO "do" TOK_WHILE "while" TOK_UNTIL "until"

%token <sval> TOK_ID "identifier" TOK_DIGIT "digit"

%type <ast> instr expr simple_instr functions esl_command
%type <ast> rule_while rule_until rule_if do_group else_group

%type <lval> compound_list id_list param_list

%left "+" "-"
%left "*" "/" "%"

%%

input   :
        |input instr { if ($2) driver.ast()->add($2); }
        ;

instr   :
        simple_instr "\n" { $$ = $1; }
        |functions "\n" { $$ = $1; }
        |esl_command "\n" { $$ = $1; }
        |"\n" { $$ = NULL; }
        |error "\n" { $$ = NULL; }
        ;

compound_list   :
                simple_instr "\n" { $$ = new std::list<esl_ast *>;
                                    $$->push_back($1); }
                |esl_command "\n"  { $$ = new std::list<esl_ast *>;
                                    $$->push_back($1); }
                | compound_list simple_instr "\n"
                                    { $$ = $1;
                                    $$->push_back($2); }
                | compound_list esl_command "\n"
                                    { $$ = $1;
                                    $$->push_back($2); }
                ;

param_list         :
                "identifier"
                             { $$ = new std::list<esl_ast *>;
                               $$->push_back(new esl_ast(ID, *$1));
                               delete $1;
                             }
                |"identifier" "\n"
                             { $$ = new std::list<esl_ast *>;
                               $$->push_back(new esl_ast(ID, *$1));
                               delete $1;
                             }
                | param_list "," "identifier"
                             { $$ = $1;
                               $$->push_back(new esl_ast(ID, *$3));
                               delete $3;
                             }
                | param_list "," "identifier" "\n"
                             { $$ = $1;
                               $$->push_back(new esl_ast(ID, *$3));
                               delete $3;
                             }
                ;


id_list         :
                simple_instr
                             { $$ = new std::list<esl_ast *>;
                               $$->push_back($1);
                             }
                |simple_instr "\n"
                             { $$ = new std::list<esl_ast *>;
                               $$->push_back($1);
                             }
                | id_list "," simple_instr
                             { $$ = $1;
                               $$->push_back($3);
                             }
                | id_list "," simple_instr "\n"
                             { $$ = $1;
                               $$->push_back($3);
                             }
                ;

simple_instr    :
                expr { $$ = new esl_ast(EXPR, ""); $$->add($1); }
                |"identifier" "(" ")" {
                                        $$ = new esl_ast(FUNCTION_CALL,
                                                         std::string(*$1));
                                        delete $1;
                                      }
                |"identifier" "(" id_list ")"
                                      {
                                        $$ = new esl_ast(FUNCTION_CALL,
                                                         std::string(*$1));
                                        $$->add(esl_ast::ast_from_list($3));
                                        $$->get_fson()->set_token(LIST);
                                        delete $1;
                                      }

                |"identifier" "=" simple_instr {
                                         $$ = new esl_ast(ASSIGNEMENT, "");
                                         $$->add(new esl_ast(ID, *$1));
                                         $$->add($3);
                                         delete $1;
                                       }
                ;
functions       :
                "function" "identifier" "(" ")" "\n" compound_list "end"
                                        {
                                            $$ = new esl_ast(FUNCTION_DECL,
                                                             *$2);
                                            delete $2;
                                            $$->add(new esl_ast(EMPTY, ""));
                                            $$->add(esl_ast::ast_from_list($6));
                                        }
                |"function" "identifier" "(" param_list ")" "\n" compound_list "end"
                                        {
                                            $$ = new esl_ast(FUNCTION_DECL,
                                                             *$2);
                                            delete $2;
                                            $$->add(esl_ast::ast_from_list($4));
                                            $$->get_fson()->set_token(LIST);

                                            $$->add(esl_ast::ast_from_list($7));
                                        }
                ;
expr            :
                expr "+" expr
                                {
                                    $$ = new esl_ast(ADD, "");
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "-" expr
                                {
                                    $$ = new esl_ast(MINUS, "");
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "*" expr
                                {
                                    $$ = new esl_ast(MUL, "");
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "/" expr
                                {
                                    $$ = new esl_ast(DIV, "");
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "%" expr
                                {
                                    $$ = new esl_ast(MOD, "");
                                    $$->add($1);
                                    $$->add($3);
                                }
                |"(" expr ")"   { $$ = $2; }
                |"digit" { $$ = new esl_ast(NUMBER, *$1); delete $1;}
                |"identifier" { $$ = new esl_ast(ID, *$1); delete $1;}
                ;

esl_command     :
                rule_if { $$ = $1; }
                |rule_until { $$ = $1; }
                |rule_while { $$ = $1; }
                ;

rule_if         :
                "if" simple_instr "then" "\n" compound_list else_group "end"
                                                    {
                                                      $$ = new esl_ast(IF, "");
                                                      $$->add($2);
                                                      $$->add(esl_ast::ast_from_list($5));
                                                      $$->add($6);
                                                    }

                |"if" simple_instr "then" "\n" compound_list "end"
                                                    {
                                                      $$ = new esl_ast(IF, "");
                                                      $$->add($2);
                                                      $$->add(esl_ast::ast_from_list($5));
                                                    }
                ;

else_group      :
                "else" "\n" compound_list { $$ = esl_ast::ast_from_list($3); }
                |"elif" simple_instr "then" "\n" compound_list
                                                {
                                                  $$ = new esl_ast(IF, "");
                                                  $$->add($2);
                                                  $$->add(esl_ast::ast_from_list($5));
                                                }
                |"elif" simple_instr "then" "\n" compound_list else_group
                                                {
                                                  $$ = new esl_ast(IF, "");
                                                  $$->add($2);
                                                  $$->add(esl_ast::ast_from_list($5));
                                                  $$->add($6);
                                                }
                ;

rule_while      :
                "while" simple_instr do_group {
                                                $$ = new esl_ast(WHILE, "");
                                                $$->add($2);
                                                $$->add($3);
                                              }
                ;

rule_until      :
                "until" simple_instr do_group {
                                                $$ = new esl_ast(UNTIL, "");
                                                $$->add($2);
                                                $$->add($3);
                                              }
                ;

do_group        :
                "do" "\n" compound_list "end" {
                                                $$ = esl_ast::ast_from_list($3);
                                              }
                ;
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                               const std::string& m)
{
    driver.error(l, m);
}
