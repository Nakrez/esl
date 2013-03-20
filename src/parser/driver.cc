#include <parser/driver.hh>
#include <string>
#include <algorithm>

Driver::Driver()
    : ast_(nullptr)
{
    errors_ = 0;
}

Driver::~Driver()
{
    delete ast_;
}

void Driver::free()
{
    delete this->ast_;
}

int Driver::errors_get ()
{
    return this->errors_;
}

ast::Ast* Driver::parser(const std::string& filename)
{
    std::string old_file = file_;
    ast::Ast* old_ast = ast_;

    file_ = filename;

    yy::eslxx_parser parser(*this);
    scan_begin();
    parser.parse();
    scan_end();

    file_ = old_file;
    ast::Ast* temp = ast_;
    ast_ = old_ast;

    return temp;
}
