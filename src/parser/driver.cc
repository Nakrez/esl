#include "driver.hh"
#include <string>
#include <algorithm>
#include "compile/compiler.hh"

struct main_params params;

Driver::Driver()
{
    this->gen_ast_ = new esl::Ast(STATEMENTS);
    errors_ = 0;
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
    int res;
    if(!t.compare("file")){
        this->file_ = f;
        yy::eslxx_parser parser(*this);
        scan_begin();
        res = parser.parse();
        scan_end();
        if(params.byte){
            esl::Compiler *compiler = nullptr;
            compiler = new esl::Compiler(this->ast());
            compiler->export_bytecode("byte.eslc");
       }
       if(params.ast){
           this->gen_ast_->print();
       }
    }else{
        std::string s=f;
        s.erase(0,2);
        if(s.compare("ast")){
            params.ast = true;
        }
        if(s.compare("byte")){
           params.byte = true;
        }
    return res;
}
