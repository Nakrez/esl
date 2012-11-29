%skeleton "lalr1.cc"
%code requires
{
#include <string>

#include "utils/esl_ast.hh"

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
    std::string *sval;
    esl_ast     *ast;
}

%code
{
#include <eslxx_driver.hh>
}

%token END       0 "end_of_file"
%token TOK_NEWLINE "\n" TOK_EQ "="
%token TOK_PLUS "+" TOK_MINUS "-" TOK_MUL "*" TOK_DIV "/" TOK_MOD "%"
%token TOK_PAROPEN "(" TOK_PARCLOSE ")"
%token TOK_IF "if" TOK_THEN "then" TOK_ELSE "else" TOK_ELIF "elif"
%token TOK_END "end"
%token TOK_FUNCTION "function"
%token TOK_FOR "for" TOK_DO "do" TOK_WHILE "while" TOK_UNTIL "until"

%token <sval> TOK_ID "identifier" TOK_DIGIT "digit"

%type <ast> instr expr simple_instr functions esl_command compound_list
%type <ast> rule_while rule_until rule_if do_group else_group

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
                simple_instr "\n" { driver.compound()->add($1); }
                |esl_command "\n" { driver.compound()->add($1); }
                | compound_list simple_instr "\n" { driver.compound()->add($2); }
                | compound_list esl_command "\n" { driver.compound()->add($2); }
                ;

simple_instr    :
                expr { $$ = $1; }
                |"identifier" "(" ")" {
                                        $$ = new esl_ast(FUNCTION_CALL,
                                                         std::string(*$1));
                                      }
                |"identifier" "=" expr {
                                         $$ = new esl_ast(ASSIGNEMENT, "");
                                         $$->add(new esl_ast(ID, *$1));
                                         $$->add($3);
                                       }
                ;
functions       :
                "function" "identifier" "(" ")" "\n" compound_list "end"
                                        {
                                            $$ = new esl_ast(FUNCTION_DECL,
                                                             *$2);
                                            $$->add(driver.compound());
                                            driver.reset_compound();
                                        }
                ;
expr            :
                expr "+" expr
                                {
                                    $$ = new esl_ast(ADD, "");
                                    $$->add($1);
                                    $$->add($3);
                                }
                |"digit" { $$ = new esl_ast(NUMBER, *$1); }
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
                                                      $$->add(driver.compound());
                                                      driver.reset_compound();
                                                      $$->add($6);
                                                    }

                |"if" simple_instr "then" "\n" compound_list "end"
                                                    {
                                                      $$ = new esl_ast(IF, "");
                                                      $$->add($2);
                                                      $$->add(driver.compound());
                                                      driver.reset_compound();
                                                    }
                ;

else_group      :
                "else" "\n" compound_list { $$ = driver.compound(); driver.reset_compound(); }
                |"elif" simple_instr "then" "\n" compound_list
                                                {
                                                  $$ = new esl_ast(IF, "");
                                                  $$->add($2);
                                                  $$->add(driver.compound());
                                                  driver.reset_compound();
                                                }
                |"elif" simple_instr "then" "\n" compound_list else_group
                                                {
                                                  $$ = new esl_ast(IF, "");
                                                  $$->add($2);
                                                  $$->add(driver.compound());
                                                  driver.reset_compound();
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
                                                $$ = driver.compound();
                                                driver.reset_compound();
                                              }
                ;
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                               const std::string& m)
{
    driver.error(l, m);
}
