#ifndef LIBPARSER_HH
# define LIBPARSER_HH

# include <string>

# include <parser/driver.hh>
# include <ast/ast.hh>

namespace parser
{
    extern ast::Ast* main_ast;

    void parse_input_file(const std::string& name);
} // namespace parser

#endif /* !LIBPARSER_HH */
