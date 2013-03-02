#include "driver.hh"
#include <string>
#include <algorithm>
#include "../compile/compiler.hh"
#include "../utils/option.hh"

Driver::Driver()
{
    this->gen_ast_ = new esl::Ast(STATEMENTS);
    errors_ = 0;
    byte_bool = false;
    ast_bool = false;
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
        if(ast_bool) inst.ast_optn(this);
        if(byte_bool) inst.byte_optn(this);
    }
    else
    {
        std::string s=f;
        s.erase(0,2);
        if (!s.compare("ast")) ast_bool = true;
        else if (!s.compare("byte")) byte_bool = true;
        else if (!s.compare("ee")) inst.ee_optn();
        else
            std::cerr << "Unknown option : " << s << std::endl;
    }

    return res;
}
