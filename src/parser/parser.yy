%require "2.4"
%skeleton "lalr1.cc"
%code requires
{

#include <string>
#include <list>

#include <ast/ast.hh>

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
        | input instr { if ($instr) driver.ast()->add($instr); }
        ;

instr   :
        expr { $$ = $1; }
        |functions { $$ = $1; }
        |class_decl { $$ = $1; }
        |esl_command { $$ = $1; }
        |"import" "string" { $$ = new ast::Ast(IMPORT, $2); }
        |"include" "string"
        ;

class_decl:
          "class" "identifier" class_components "end"
          {
            $$ = new ast::Ast(CLASS_DECL, $2);
            $$->add(new ast::Ast(EMPTY));
            $$->add(ast::Ast::ast_from_list($3));
          }
          |"class" "identifier" ":" "(" param_list ")" class_components "end"
          {
            $$ = new ast::Ast(CLASS_DECL, $2);
            $$->add(ast::Ast::ast_from_list($5));
            $$->add(ast::Ast::ast_from_list($7));
          }
          ;

visibility :
           | "public"
           | "private"
           | "protected"
           ;

class_component:
                visibility functions { $$ = $2; }
                |visibility "identifier" { $$ = new ast::Ast(ID, $2); }
                |visibility "identifier" "=" expr
                {
                  $$ = new ast::Ast(ASSIGNEMENT);
                  $$->add(new ast::Ast(ID, $2));
                  $$->add($4);
                }
                ;

class_components:
                class_component
                {
                    $$ = new std::list<ast::Ast*>;
                    $$->push_back($1);
                }
                |class_components class_component
                {
                    $$ = $1;
                    $$->push_back($2);
                }
                ;

compound_list   :
                "return" expr
                        {
                          $$ = new std::list<ast::Ast*>;
                          ast::Ast* tmp = new ast::Ast(RETURN_STM);
                          tmp->add($2);
                          $$->push_back(tmp);
                        }
                |expr { $$ = new std::list<ast::Ast *>;
                                    $$->push_back($1); }
                |esl_command  { $$ = new std::list<ast::Ast *>;
                                    $$->push_back($1); }
                | compound_list expr
                                    { $$ = $1;
                                    $$->push_back($2); }
                | compound_list esl_command
                                    { $$ = $1;
                                    $$->push_back($2); }
                | compound_list "return" expr
                                    { $$ = $1;
                                      ast::Ast* tmp = new ast::Ast(RETURN_STM);
                                      tmp->add($3);
                                      $$->push_back(tmp);
                                    }

                ;

object_call_list:
                expr "->" "identifier"
                {
                    $$ = new ast::Ast(CLASS_ATTRIBUT);
                    $$->add($1);
                    $$->add(new ast::Ast(ID, $3));
                }
                |expr "->" fun_call
                {
                    $$ = new ast::Ast(METHOD_CALL);
                    $$->add($1);
                    $$->add($3);
                }
                |object_call_list "->" "identifier"
                {
                    $$ = new ast::Ast(CLASS_ATTRIBUT);
                    $$->add($1);
                    $$->add(new ast::Ast(ID, $3));
                }
                |object_call_list "->" fun_call
                {
                    $$ = new ast::Ast(METHOD_CALL);
                    $$->add($1);
                    $$->add($3);
                }
                ;
param_list      :
                "identifier"
                             { $$ = new std::list<ast::Ast *>;
                               $$->push_back(new ast::Ast(ID, $1));
                             }
                | param_list "," "identifier"
                             { $$ = $1;
                               $$->push_back(new ast::Ast(ID, $3));
                             }
                ;

id_list         :
                expr
                             { $$ = new std::list<ast::Ast *>;
                               $$->push_back($1);
                             }
                | id_list "," expr
                             { $$ = $1;
                               $$->push_back($3);
                             }
                ;

fun_call        :
                "identifier" "(" ")" { $$ = new ast::Ast(FUNCTION_CALL, $1); }
                |"identifier" "(" id_list ")"
                                      {
                                        $$ = new ast::Ast(FUNCTION_CALL, $1);
                                        $$->add(ast::Ast::ast_from_list($3));
                                        $$->get_fson()->set_token(LIST);
                                      }
                ;
functions       :
                "function" "identifier" "(" ")" compound_list "end"
                                        {
                                          $$ = new ast::Ast(FUNCTION_DECL, $2);
                                          $$->add(new ast::Ast(EMPTY));
                                          $$->add(ast::Ast::ast_from_list($5));
                                        }
                |"function" "identifier" "(" param_list ")" compound_list "end"
                                        {
                                          $$ = new ast::Ast(FUNCTION_DECL, $2);
                                          $$->add(ast::Ast::ast_from_list($4));
                                          $$->get_fson()->set_token(LIST_ID);
                                          $$->add(ast::Ast::ast_from_list($6));
                                        }
                ;

arrays          :
                 "[" expr "]"  {
                                 $$ = new std::list<ast::Ast *>;
                                 $$->push_back($2);
                               }
                | arrays "[" expr "]" {
                                        $$ = $1;
                                        $$->push_back($3);
                                      }
                ;

expr            :
                expr "+" expr
                                {
                                    $$ = new ast::Ast(ADD);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "-" expr
                                {
                                    $$ = new ast::Ast(MINUS);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "*" expr
                                {
                                    $$ = new ast::Ast(MUL);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "/" expr
                                {
                                    $$ = new ast::Ast(DIV);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "%" expr
                                {
                                    $$ = new ast::Ast(MOD);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "^" expr
                                {
                                    $$ = new ast::Ast(POW);
                                    $$->add($1);
                                    $$->add($3);
                                }

                |expr "==" expr
                                {
                                    $$ = new ast::Ast(EQ);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "!=" expr
                                {
                                    $$ = new ast::Ast(DIFF);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr ">" expr
                                {
                                    $$ = new ast::Ast(GT);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr ">=" expr
                                {
                                    $$ = new ast::Ast(GE);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "<" expr
                                {
                                    $$ = new ast::Ast(LT);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "<=" expr
                                {
                                    $$ = new ast::Ast(LE);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "&&" expr
                                {
                                    $$ = new ast::Ast(AND);
                                    $$->add($1);
                                    $$->add($3);
                                }
                |expr "||" expr
                                {
                                    $$ = new ast::Ast(OR);
                                    $$->add($1);
                                    $$->add($3);
                                }

                |"(" expr ")"   { $$ = $2; }
                |"digit" { $$ = new ast::Ast(NUMBER, $1); }
                |"string" { $$ = new ast::Ast(STRING, $1); }
                |"identifier" { $$ = new ast::Ast(ID, $1); }
                |fun_call { $$ = $1; }
                |object_call_list { $$ = $1; }
                |"new" fun_call {
                                  $$ = new ast::Ast(NEW);
                                  $$->add($2);
                                }
                |"identifier" "=" expr {
                                         $$ = new ast::Ast(ASSIGNEMENT);
                                         $$->add(new ast::Ast(ID, $1));
                                         $$->add($3);
                                       }
                | object_call_list "=" expr
                                       {
                                         $$ = new ast::Ast(ASSIGNEMENT);
                                         $$->add($1);
                                         $$->add($3);
                                       }
                |"mod_id" "." fun_call
                                         {
                                            $$ = new ast::Ast(MODULE_CALL, $1);
                                            $$->add($3);
                                         }
                |"identifier" arrays "=" expr
                                     {
                                         $$ = new ast::Ast(ASSIGNEMENT_ARRAY);
                                         $$->add(new ast::Ast(ID, $1));
                                         $$->add(new ast::Ast(EXPR,
                                                              ast::Ast::ast_from_list($2)));
                                         $$->add(new ast::Ast(EXPR, $4));
                                     }
                |"identifier" arrays
                            {
                                $$ = new ast::Ast(ARRAY_AT);
                                $$->add(new ast::Ast(ID, $1));
                                $$->add(ast::Ast::ast_from_list($2));
                            }
                ;

esl_command     :
                rule_if { $$ = $1; }
                |rule_until { $$ = $1; }
                |rule_while { $$ = $1; }
                ;

rule_if         :
                "if" expr "then" compound_list else_group "end"
                                                    {
                                                      $$ = new ast::Ast(IF);
                                                      $$->add($2);
                                                      $$->add(ast::Ast::ast_from_list($4));
                                                      $$->add($5);
                                                    }

                |"if" expr "then" compound_list "end"
                                                    {
                                                      $$ = new ast::Ast(IF);
                                                      $$->add($2);
                                                      $$->add(ast::Ast::ast_from_list($4));
                                                    }
                ;

else_group      :
                "else" compound_list { $$ = ast::Ast::ast_from_list($2); }
                |"elif" expr "then" compound_list
                                                {
                                                  $$ = new ast::Ast(IF);
                                                  $$->add($2);
                                                  $$->add(ast::Ast::ast_from_list($4));
                                                }
                |"elif" expr "then" compound_list else_group
                                                {
                                                  $$ = new ast::Ast(IF);
                                                  $$->add($2);
                                                  $$->add(ast::Ast::ast_from_list($4));
                                                  $$->add($5);
                                                }
                ;

rule_while      :
                "while" expr do_group {
                                                $$ = new ast::Ast(WHILE);
                                                $$->add($2);
                                                $$->add($3);
                                              }
                ;

rule_until      :
                "until" expr do_group {
                                                $$ = new ast::Ast(UNTIL);
                                                $$->add($2);
                                                $$->add($3);
                                              }
                ;

do_group        :
                "do" compound_list "end" {
                                                $$ = ast::Ast::ast_from_list($2);
                                              }
                ;
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                               const std::string& m)
{
    driver.error(l, m);
}
