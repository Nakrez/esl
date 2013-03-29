#include <parser/libparser.hh>

namespace parser
{
    ast::Ast* main_ast = nullptr;

    void parse_input_file(const std::string& name)
    {
        Driver driver;
        ast::Ast* generated_ast = nullptr;

        generated_ast = driver.parser(name);

        // FIXME Add driver error handling

        main_ast = generated_ast;
    }
} // namespace parser
