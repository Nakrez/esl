#include "driver.hh"
#include <string>
#include <algorithm>
#include "../compile/compiler.hh"

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

    if (!t.compare("file"))
    {
        this->file_ = f;
        yy::eslxx_parser parser(*this);
        scan_begin();
        res = parser.parse();
        scan_end();

        if (get_byte())
        {
            esl::Compiler *compiler = nullptr;
            compiler = new esl::Compiler(this->ast());
            compiler->export_bytecode("byte.eslc");
        }

        if (get_ast())
            this->gen_ast_->print();
    }
    else
    {
        std::string s=f;
        s.erase(0,2);
        if (!s.compare("ast"))
            set_ast(true);
        else if (!s.compare("byte"))
            set_byte(true);
        else if (!s.compare("ee"))
        {
            std::cout << "+      o     +              o   " << std::endl;
            std::cout << "    +             o     +       +" << std::endl;
            std::cout << "o          +" << std::endl;
            std::cout << "    o  +           +        +" << std::endl;
            std::cout << "+        o     o       +        o" << std::endl;
            std::cout << "-_-_-_-_-_-_-_,------,      o " << std::endl;
            std::cout << "_-_-_-_-_-_-_-|   /\\_/\\  " << std::endl;
            std::cout << "-_-_-_-_-_-_-~|__( ^ .^)  +     +  " << std::endl;
            std::cout << "_-_-_-_-_-_-_-\"\"  \"\"      " << std::endl;
            std::cout << "+      o         o   +       o" << std::endl;
            std::cout << "    +         +" << std::endl;
            std::cout << "o        o         o      o     +" << std::endl;
            std::cout << "    o           +" << std::endl;
            std::cout << "+      +     o        o      +" << std::endl;
            std::cout << "\033[4;35m" << "Trololol, this is Nyan Cat!"
                      << "\033[0m" << std::endl;
        }
        else
            std::cerr << "Unknown option : " << s << std::endl;
    }

    return res;
}
