#ifndef DRIVER_HH
# define DRIVER_HH

# include <stack>

# include <parser/parser.hh>
# include <ast/all.hh>
# include <utils/option.hh>

# define YY_DECL                                        \
    yy::eslxx_parser::token_type yylex(                \
            yy::eslxx_parser::semantic_type *yylval,       \
            yy::eslxx_parser::location_type *yylloc,       \
            Driver& driver)

YY_DECL;

struct yy_buffer_state;

class Driver
{
    public:
        Driver ();
        ~Driver ();
        void error (const yy::eslxx_parser::location_type& l,
                    const std::string& m);
        void scan_begin ();
        void scan_end ();
        ast::Ast* parser(const std::string& filename);
        void free ();
        int errors_get ();

    public:
        ast::Ast* ast_;

    private:
        std::stack<yy_buffer_state*> states_;
        std::string file_;
        int errors_;
};
#endif /* DRIVER_HH */
