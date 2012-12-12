#ifndef DRIVER_HH
# define DRIVER_HH

# include "parser.hh"
# include "../utils/ast.hh"

# define YY_DECL                                        \
    yy::eslxx_parser::token_type yylex(                \
            yy::eslxx_parser::semantic_type *yylval,       \
            yy::eslxx_parser::location_type *yylloc,       \
            Driver& driver)

YY_DECL;

class Driver
{
    public:
        Driver ();
        ~Driver ();
        void error (const yy::eslxx_parser::location_type& l,
                    const std::string& m);
        int parser (const std::string &f);
        void scan_begin ();
        void scan_end ();
        esl::Ast* ast ();
        void free ();
        int errors_get ();

    private:
        std::string file_;
        int errors_;
        esl::Ast* gen_ast_;
};
#endif /* DRIVER_HH */
