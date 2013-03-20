#include "option.hh"
#include "../parser/driver.hh"
#include "../compile/compiler.hh"
#include <iostream>
#include <string>

Option* Option::instance_ = nullptr;

Option::Option()
    : ast_bool(false)
{}

Option::~Option()
{}

void Option::instanciate ()
{
    if(instance_ == nullptr)
        instance_ = new Option();
}

Option* Option::get ()
{
    return instance_;
}

void Option::free ()
{
    if (instance_)
    {
        delete instance_;
        instance_ = nullptr;
    }
}

void Option::set_ast(bool tmp)
{
    ast_bool = tmp;
}

void Option::set_byte(bool tmp)
{
    byte_bool = tmp;
}

bool Option::get_ast() const
{
    return ast_bool;
}

bool Option::get_byte() const
{
    return byte_bool;
}

void Option::ee_optn()
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
