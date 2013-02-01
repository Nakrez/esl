#include "driver.hh"
#include <string>
#include <algorithm>
#include "../compile/compiler.hh"
#include "../utils/option.hh"

Driver::Driver()
{
    this->gen_ast_ = new esl::Ast(STATEMENTS);
    errors_ = 0;
    byte_param = false;
    ast_param = false;
}

Driver::~Driver()
{
}

void Driver::free()
{
    delete this->gen_ast_;
}

void Driver::error(const yy::location& l, const std::string& m)
{
    std::cerr << file_ << ":" << l << ": " << m << std::endl;
    ++errors_;
}

int Driver::errors_get ()
{
    return this->errors_;
}

esl::Ast *Driver::ast()
{
    return this->gen_ast_;
}

bool Driver::get_byte()
{
    return this->byte_param;
}

void Driver::set_byte(bool a)
{
    byte_param = a;
}

bool Driver::get_ast()
{
    return this->ast_param;
}

void Driver::set_ast(bool a)
{
    ast_param = a;
}

int Driver::parser(const std::string &f, const std::string &t)
{
    int res = 0;
    Option inst;
    if (!t.compare("file"))
    {
        this->file_ = f;
        yy::eslxx_parser parser(*this);
        scan_begin();
        res = parser.parse();
        scan_end();

        if (get_ast())
            this->gen_ast_->print();
    }
    else
    {
        std::string s=f;
        s.erase(0,2);
        if (!s.compare("ast")) inst.ast_optn();
        else if (!s.compare("byte")) inst.byte_optn();
        else if (!s.compare("ee")) inst.ee_optn();
        else
            std::cerr << "Unknown option : " << s << std::endl;
    }

    return res;
}
