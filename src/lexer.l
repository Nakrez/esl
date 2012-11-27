%{
#include <parser.hpp>
#include <eslxx_driver.hh>

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
"end"                   return token::TOK_END;

[a-z_A-Z][a-zA-Z_0-9]*  {
                            yylval->sval = new std::string(yytext);
                            return token::TOK_ID;
                        }
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

void eslxx_driver::scan_begin()
{
    if (file.empty () || file == "-")
        yyin = stdin;
    else if (!(yyin = fopen(file.c_str(), "r")))
    {
        std::cerr << "cannot open " << file << std::endl;
        exit(EXIT_FAILURE);
    }
}
void eslxx_driver::scan_end()
{
    fclose (yyin);
}
