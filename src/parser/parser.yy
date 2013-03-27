%require "2.4"
%skeleton "glr.cc"
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
%verbose
%glr-parser
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
    std::string* sval;
    int ival;

    misc::visibility vis;

    ast::Ast* ast;

    ast::Instr* ast_instr;
    ast::InstrList* ast_list_instr;

    ast::Exp* ast_exp;
    ast::FunctionCallExp* ast_funexp;
    ast::ExpList* ast_list_exp;

    ast::Var* ast_var;

    ast::FunctionDec* ast_function;
    ast::VarDec* ast_vardec;
    ast::VarDecList* ast_vardec_list;
    ast::DecList* ast_dec_list;
    ast::Dec* ast_dec;
    ast::ClassDec* ast_class;

    ast::AstList* ast_list;

    ast::IdList* ast_id_list;
}

%code
{
#include <parser/driver.hh>
}

%token  END       0         "end_of_file"
        TOK_EQ              "="
        TOK_DOT             "."
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
        TOK_NOT             "!"
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
        TOK_BREAK           "break"
        TOK_CONTINUE        "continue"
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

%token <ival>
        TOK_DIGIT           "digit"

%type <ast_exp> expr

%type <ast_funexp> fun_call

%type <ast_list_exp> exp_list

%type <ast_var> lvalue
                lvalue_assignable

%type <ast> instr
%type <ast_instr> esl_command
                  rule_if
                  rule_while
                  rule_until
                  else_group
                  compound

%type <ast_list_instr> compound_list
                       do_group

%type <ast_list>       input

%type <ast_vardec> param
%type <ast_vardec_list> param_list

%type <ast_function> function

%type <ast_class> class_decl
%type <ast_dec_list> class_components
                     class_component_list
%type <ast_dec> class_component
%type <vis> visibility
%type <ast_id_list> inherit_list

%left prec_exp

%right "identifier" "("
%right "="
%left "->" "."
%left "||" "&&"
%left "==" "!=" "<" ">" "<=" ">="
%left "+" "-"
%left "*" "/" "%"
%left "!"
%left "^"

%%
program:
       | input { driver.ast_ = $1; }
       ;

input   :
        instr
        {
            $$ = new ast::AstList(@1);
            $$->push_back($1);
        }
        | input instr
        {
            $$ = $1;
            $$->push_back($2);
        }
        ;

instr   :
        expr %prec prec_exp { $$ = $1; }
        |function { $$ = $1; }
        |class_decl { $$ = $1; }
        |esl_command { $$ = $1; }
        |"import" "string"
        {
            $$ = new ast::ImportInstr(@1, std::string(*$2));
            delete $2;
        }
        |"include" "string" { $$ = driver.parser(*$2); delete $2; }
        ;

inherit_list:
            "identifier"
            {
                $$ = new ast::IdList();
                $$->push_back(std::string(*$1));
                delete $1;
            }
            | inherit_list "," "identifier"
            {
                $$ = $1;
                $$->push_back(std::string(*$3));
                delete $3;
            }
            ;
class_decl:
          "class" "identifier" class_components "end"
          {
            $$ = new ast::ClassDec(@1, std::string(*$2), nullptr, $3);
            delete $2;
          }
          |"class" "identifier" ":" "(" inherit_list ")" class_components "end"
          {
            $$ = new ast::ClassDec(@1, std::string(*$2), $5, $7);
            delete $2;
          }
          ;

visibility : { $$ = misc::PUBLIC; }
           | "public" { $$ = misc::PUBLIC; }
           | "private" { $$ = misc::PRIVATE; }
           | "protected" { $$ = misc::PROTECTED; }
           ;

class_component:
                visibility "function" "identifier" "(" param_list ")" compound_list "end"
                {
                    $$ = new ast::MethodDec(@1, std::string(*$3), $5, $7, $1);
                    delete $3;
                }
                |visibility "identifier"
                {
                    $$ = new ast::AttributDec(@1, std::string(*$2), nullptr, $1);
                    delete($2);
                }
                |visibility "identifier" "=" expr
                {
                    $$ = new ast::AttributDec(@1, std::string(*$2), $4, $1);
                    delete $2;
                }
                ;

class_components: { $$ = new ast::DecList(@$); }
                | class_component_list { $$ = $1; }
                ;

class_component_list:
                    class_component
                    {
                        $$ = new ast::DecList(@1);
                        $$->push_back($1);
                    }
                    |class_component_list class_component
                    {
                        $$ = $1;
                        $$->push_back($2);
                    }
                    ;

compound_list   :
                compound { $$ = new ast::InstrList(@1, $1); }
                | compound_list compound
                {
                    $$ = $1;
                    $$->push_back($2);
                }
                ;
compound:
        "return" expr { $$ = new ast::ReturnExp(@1, $2); }
        | expr { $$ = $1; }
        | esl_command { $$ = $1; }
        | "break" { $$ = new ast::BreakExp(@1); }
        | "continue" { $$ = new ast::ContinueExp(@1); }
        ;

param:
     "identifier"
     {
        $$ = new ast::VarDec(@1, std::string(*$1));
        delete $1;
     }
     |"identifier" "=" expr
     {
        $$ = new ast::VarDec(@1, std::string(*$1), $3);
        delete $1;
     }
     ;

param_list      :
                { $$ = new ast::VarDecList(@$); }
                | param
                {
                    $$ = new ast::VarDecList(@1, $1);
                }
                | param_list "," param
                {
                    $$ = $1;
                    $$->push_back($3);
                }
                ;

exp_list        :
                { $$ = new ast::ExpList(@$); }
                | expr { $$ = new ast::ExpList(@1, $1); }
                | exp_list "," expr
                {
                    $$ = $1;
                    $$->push_back($3);
                }
                ;

fun_call        :
                "identifier" "(" exp_list ")"
                {
                    $$ = new ast::FunctionCallExp(@1, std::string(*$1), $3);
                    delete $1;
                }
                ;

function        :
                "function" "identifier" "(" param_list ")" compound_list "end"
                {
                    $$ = new ast::FunctionDec(@1, std::string(*$2), $4, $6);
                    delete $2;
                }
                ;

expr            :
                "!" expr
                {
                    $$ = new ast::OpExp(@1,
                                        $2,
                                        ast::OpExp::Operator::not_,
                                        nullptr);
                }
                | "-" expr 
                {
                  $$ = new ast::OpExp(@2,
                                      new ast::IntExp(@1, 0),
                                      ast::OpExp::Operator::min,
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
                |"string"
                {
                    $$ = new ast::StringExp(@1, std::string(*$1));
                    delete $1;
                }
                |fun_call { $$ = $1; }
                |"new" fun_call { $$ = new ast::NewExp(@1, $2); }
                |lvalue { $$ = $1; }
                |lvalue_assignable "=" expr
                {
                    $$ = new ast::AssignExp(@1, $1, $3);
                }
                ;

lvalue_assignable:
      "identifier"
      {
        $$ = new ast::VarId(@1, std::string(*$1));
        delete $1;
      }
      | lvalue "->" "identifier"
      {
        $$ = new ast::AttributVar(@1, *$1, std::string(*$3));
        delete $3;
      }
      | lvalue "[" expr "]" { $$ = new ast::ArrayVar(@1, $1, $3); }
      ;

lvalue:
      "identifier"
      {
        $$ = new ast::VarId(@1, std::string(*$1));
        delete $1;
      }
      | lvalue "->" "identifier"
      {
        $$ = new ast::AttributVar(@1, *$1, std::string(*$3));
        delete $3;
      }
      | lvalue "->" fun_call { $$ = new ast::MethodCallVar(@1, $1, $3); }
      /* Not Handled by VM yet */
      | lvalue "." "identifier"
      {
        $$ = new ast::ModuleAttributVar(@1, $1, std::string(*$3));
        delete $3;
      }
      | lvalue "." fun_call { $$ = new ast::ModuleCallVar(@1, $1, $3); }
      | lvalue "[" expr "]" { $$ = new ast::ArrayVar(@1, $1, $3); }
      ;

esl_command     :
                rule_if { $$ = $1; }
                |rule_until { $$ = $1; }
                |rule_while { $$ = $1; }
                ;

rule_if         :
                "if" expr "then" compound_list else_group "end"
                {
                  $$ = new ast::IfInstr(@1, $2, $4, $5);
                }
                |"if" expr "then" compound_list "end"
                {
                  $$ = new ast::IfInstr(@1, $2, $4);
                }
                ;

else_group      :
                "else" compound_list { $$ = new ast::ElseInstr(@1, $2); }
                |"elif" expr "then" compound_list
                {
                    $$ = new ast::IfInstr(@1, $2, $4);
                }
                |"elif" expr "then" compound_list else_group
                {
                    $$ = new ast::IfInstr(@1, $2, $4, $5);
                }
                ;

rule_while      :
                "while" expr do_group
                {
                    $$ = new ast::WhileInstr(@1, $2, $3);
                }
                ;

rule_until      :
                "until" expr do_group
                {
                    $$ = new ast::WhileInstr(@1,
                                             new ast::OpExp(@2,
                                                            $2,
                                                            ast::OpExp::Operator::not_,
                                                            nullptr),
                                            $3);
                }
                ;

do_group        :
                "do" compound_list "end" { $$ = $2; }
                ;
%%
void yy::eslxx_parser::error (const yy::eslxx_parser::location_type& l,
                              const std::string& m)
{
    std::cerr << l << m << std::endl;
}

