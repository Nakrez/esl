#include <parser/driver.hh>
#include <string>
#include <algorithm>

Driver::Driver()
    : ast_(nullptr)
{
    errors_ = 0;
    byte_param = false;
    ast_param = false;
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

int Driver::parser(const std::string &f, const std::string &t)
{
    int res = 0;

    if (!t.compare("file"))
    {
        ast_ = parser(f);

        /*if (get_ast())
            this->gen_ast_->print();*/
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
