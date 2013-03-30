#include <parser/libparser.hh>

namespace parser
{
    misc::Error parse_input_file(const std::string& name)
    {
        Driver driver;
        ast::Ast* generated_ast = nullptr;

        generated_ast = driver.parser(name);

        ast::main_ast = generated_ast;

        return driver.error_;
    }
} // namespace parser
