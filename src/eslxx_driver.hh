#ifndef ESLXX_DRIVER_H_
# define ESLXX_DRIVER_H_

# include <parser.hpp>
# include <utils/esl_ast.hh>

# define YY_DECL                                        \
    yy::eslxx_parser::token_type yylex(                \
        yy::eslxx_parser::semantic_type *yylval,       \
        yy::eslxx_parser::location_type *yylloc,       \
        eslxx_driver& driver)

YY_DECL;

class eslxx_driver
{
    public:
        eslxx_driver();
        ~eslxx_driver();
        void error(const yy::eslxx_parser::location_type& l,
                   const std::string& m);
        int parser(const std::string &f);
        void scan_begin();
        void scan_end();
        esl_ast *ast();
        void free();

    private:
        std::string file;
        esl_ast     *gen_ast;
};
#endif /* ESLXX_DRIVER_H_ */
