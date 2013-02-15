%{
#include "esl-parser.hh"
#include "driver.hh"

# undef yywrap
# define yywrap() 1
# define yyterminate() return token::END
%}

%option nounput noyywrap noinput stack

%{
# define YY_USER_ACTION  yylloc->columns (yyleng);
%}

%x COMMENT_MULTI
%x COMMENT_SIMPLE
%x LITTERAL

%%
%{
    yylloc->step();
%}
%{
    typedef yy::eslxx_parser::token token;
%}


#\[                     yy_push_state(COMMENT_MULTI);

<COMMENT_MULTI>"]#"     yy_pop_state();
<COMMENT_MULTI>"\n"     {
                            yylloc->lines(yyleng);
                            yylloc->step();
                        }
<COMMENT_MULTI>.        yylloc->step();

"#"                     BEGIN(COMMENT_SIMPLE);
<COMMENT_SIMPLE>"\n"    {
                            BEGIN(INITIAL);
                            yylloc->lines(yyleng);
                            yylloc->step();
                        }
<COMMENT_SIMPLE>[^\n]*

"if"                    return token::TOK_IF;
"then"                  return token::TOK_THEN;
"else"                  return token::TOK_ELSE;
"elif"                  return token::TOK_ELIF;
"end"                   return token::TOK_END;
"function"              return token::TOK_FUNCTION;
"do"                    return token::TOK_DO;
"while"                 return token::TOK_WHILE;
"until"                 return token::TOK_UNTIL;
"return"                return token::TOK_RETURN;
"import"                return token::TOK_IMPORT;
"include"               return token::TOK_INCLUDE;
"true"                  yylval->ival = 1; return token::TOK_DIGIT;
"false"                 yylval->ival = 0; return token::TOK_DIGIT;
"and"                   return token::TOK_AND;
"or"                    return token::TOK_OR;
"class"                 return token::TOK_CLASS;
"public"                return token::TOK_PUBLIC;
"protected"             return token::TOK_PROTECTED;
"private"               return token::TOK_PRIVATE;
"new"                   return token::TOK_NEW;

<LITTERAL>"\""          {
                            BEGIN(INITIAL);
                            if (yylval->sval == nullptr)
                                yylval->sval = new std::string;
                            return token::TOK_STRING;
                        }
<LITTERAL>\\[\\"nr]     {
                            if (yylval->sval)
                                *(yylval->sval) += yytext;
                            else
                                yylval->sval = new std::string(yytext);
                            yylloc->step();
                        }
<LITTERAL>\\.           {
                          std::string err = "scan error, unreconized escape : ";
                          err += yytext;
                          driver.error(*yylloc, err);
                          yylloc->step();
                        }
<LITTERAL>[^\\"]*       {
                            if (yylval->sval)
                                *(yylval->sval) += yytext;
                            else
                                yylval->sval = new std::string(yytext);
                            yylloc->step();
                        }
"\""                    BEGIN(LITTERAL); yylval->sval = nullptr;

[A-Z][a-zA-Z_]*         {
                            yylval->sval = new std::string(yytext);
                            return token::TOK_MOD_ID;
                        }
[a-z_A-Z][a-zA-Z_0-9]*  {
                            yylval->sval = new std::string(yytext);
                            return token::TOK_ID;
                        }
"=="                    return token::TOK_BIN_EQ;
"<>"                    return token::TOK_DIFF;
"!="                    return token::TOK_DIFF;
">"                     return token::TOK_GT;
">="                    return token::TOK_GE;
"<"                     return token::TOK_LT;
"<="                    return token::TOK_LE;
"&&"                    return token::TOK_AND;
"||"                    return token::TOK_OR;
","                     return token::TOK_COMA;
"+"                     return token::TOK_PLUS;
"-"                     return token::TOK_MINUS;
"*"                     return token::TOK_MUL;
"/"                     return token::TOK_DIV;
"%"                     return token::TOK_MOD;
"^"                     return token::TOK_POW;
"="                     return token::TOK_EQ;
"("                     return token::TOK_PAROPEN;
")"                     return token::TOK_PARCLOSE;
"."                     return token::TOK_DOT;
"["                     return token::TOK_BRACKET_OP;
"]"                     return token::TOK_BRACKET_CL;
";"                     return token::TOK_SEPARATOR;
":"                     return token::TOK_DOUBLEP;
"->"                    return token::TOK_ARROW;

[0-9]+                  {
                            yylval->ival = atoi(yytext);
                            return token::TOK_DIGIT;
                        }
"\n"                    {
                            yylloc->lines(yyleng);
                            yylloc->step();
                        }
[ \t]+                  yylloc->step();

.                       {
                          std::string err = "scan error, unknow character : '";
                          err += yytext;
                          err += "'";
                          driver.error(*yylloc, err); 
                        }
%%

void Driver::scan_begin()
{
    if (this->file_.empty() || this->file_ == "-")
        yyin = stdin;
    else if (!(yyin = fopen(this->file_.c_str(), "r")))
    {
        std::cerr << "cannot open " << this->file_ << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Driver::scan_end()
{
    fclose (yyin);
    yylex_destroy();
}
