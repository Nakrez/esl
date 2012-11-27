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
%token TOK_IF "if" TOK_THEN "then" TOK_ELSE "else" TOK_END "end"

%token <sval> TOK_ID "identifier" TOK_DIGIT "digit"

%type  <ast>  instr statement expr control rule_if

%left "+" "-"
%left "*" "/" "%"
%%

input       :
            | input instr
            ;

instr       :
            statement "\n"{ driver.ast()->add($1); }
            |control "\n"
            |"\n" { $$ = new esl_ast(EMPTY, ""); }
            |error "\n" { $$ = new esl_ast(EMPTY, ""); }
            ;

control     :
            rule_if { $$ = $1; }
            ;
new_line    :
            new_line "\n"
            |"\n"

rule_if     :
            "if" statement "then" new_line instr "end" {
                                                $$ = new esl_ast(IF, "");
                                                $$->add($2);
                                                $$->add($5);
                                              }
            |"if" statement "then" new_line instr "else" new_line instr "end"
                                              {
                                                $$ = new esl_ast(IF, "");
                                                $$->add($2);
                                                $$->add($5);
                                                $$->add($8);
                                              }
            |"if" statement "then" new_line instr "else" rule_if "end"
                                              {
                                                $$ = new esl_ast(IF, "");
                                                $$->add($2);
                                                $$->add($5);
                                                $$->add($7);
                                              }
            ;
statement   :
            "identifier" "=" expr {
                                    $$ = new esl_ast(ASSIGNEMENT, "");
                                    $$->add(new esl_ast(ID, *$1));
                                    $$->add($3);
                                  }
            |expr { $$ = $1; }
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
            |"(" expr ")"  { $$ = $2; }
            |"digit" { $$ = new esl_ast(NUMBER, *$1); }
            |"identifier" { $$ = new esl_ast(ID, *$1); }
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                               const std::string& m)
{
    driver.error(l, m);
}
