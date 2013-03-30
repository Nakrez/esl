#ifndef DRIVER_HH
# define DRIVER_HH

# include <stack>
# include <string>
# include <algorithm>

# include <misc/error.hh>

# include <parser/parser.hh>

# include <ast/all.hh>

# define YY_DECL                                        \
    yy::eslxx_parser::token_type yylex(                \
            yy::eslxx_parser::semantic_type *yylval,       \
            yy::eslxx_parser::location_type *yylloc,       \
            parser::Driver& driver)

YY_DECL;

struct yy_buffer_state;

namespace parser
{
    class Driver
    {
        public:
            Driver ();
            ~Driver ();
            void scan_begin ();
            void scan_end ();
            ast::Ast* parser(const std::string& filename);
            void free ();

        public:
            ast::Ast* ast_;
            misc::Error error_;

        private:
            std::stack<yy_buffer_state*> states_;
            std::string file_;
    };
} // namespace parser

#endif /* DRIVER_HH */
