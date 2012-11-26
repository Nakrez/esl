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

%token <sval> TOK_ID "identifier" TOK_DIGIT "digit"

%type  <ast>  assignation expr

%left "+" "-"
%left "*" "/" "%"
%%

input       :
            | input instr
            ;

instr       :
            assignation { driver.ast()->add($1); }
            ;

assignation :
            "identifier" "=" expr "\n" {
                                         $$ = new esl_ast(ASSIGNEMENT, "");
                                         $$->add(new esl_ast(ID, *$1));
                                         $$->add($3);
                                       }
            | error "\n" { $$ = new esl_ast(EMPTY, ""); }
            ;

expr        :
             expr "+" expr {
                             $$ = new esl_ast(ADD, "");
                             $$->add($1); $$->add($3);
                           }
            |expr "-" expr {
                             $$ = new esl_ast(MINUS, "");
                             $$->add($1); $$->add($3);
                           }
            |expr "*" expr {
                             $$ = new esl_ast(MUL, "");
                             $$->add($1); $$->add($3);
                           }
            |expr "/" expr {
                             $$ = new esl_ast(DIV, "");
                             $$->add($1); $$->add($3);
                           }
            |expr "%" expr {
                             $$ = new esl_ast(MOD, "");
                             $$->add($1); $$->add($3);
                           }
            |"digit" { $$ = new esl_ast(NUMBER, *$1); }
            |"identifier" { $$ = new esl_ast(ID, *$1); }
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                               const std::string& m)
{
    driver.error(l, m);
}
