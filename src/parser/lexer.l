%{
#include "parser.hh"
#include "driver.hh"

# undef yywrap
# define yywrap() 1
# define yyterminate() return token::END
%}

%option nounput noyywrap noinput

%{
# define YY_USER_ACTION  yylloc->columns (yyleng);
%}
%%
%{
    yylloc->step();
%}
%{
    typedef yy::eslxx_parser::token token;
%}

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

[a-z_A-Z][a-zA-Z_0-9]*  {
                            yylval->sval = new std::string(yytext);
                            return token::TOK_ID;
                        }
","                     return token::TOK_COMA;
"+"                     return token::TOK_PLUS;
"-"                     return token::TOK_MINUS;
"*"                     return token::TOK_MUL;
"/"                     return token::TOK_DIV;
"%"                     return token::TOK_MOD;
"="                     return token::TOK_EQ;
"("                     return token::TOK_PAROPEN;
")"                     return token::TOK_PARCLOSE;
[0-9]+                  {
                            yylval->sval = new std::string(yytext);
                            return token::TOK_DIGIT;
                        }
"\n"                    {
                            yylloc->lines(yyleng);
                            yylloc->step();
                            return token::TOK_NEWLINE;
                        }
[ \t]+                  yylloc->step();

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
