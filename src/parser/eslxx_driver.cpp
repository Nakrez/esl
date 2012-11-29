#include <parser/eslxx_driver.hh>

eslxx_driver::eslxx_driver()
{
    gen_ast = new esl_ast(STATEMENTS, "");
}

eslxx_driver::~eslxx_driver()
{
}

void eslxx_driver::free()
{
    delete gen_ast;
}

void eslxx_driver::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

esl_ast *eslxx_driver::ast()
{
    return gen_ast;
}

int eslxx_driver::parser(const std::string &f)
{
    file = f;

    yy::eslxx_parser parser(*this);

    scan_begin();
    int res = parser.parse();
    scan_end();

    gen_ast->print();

    return res;
}
