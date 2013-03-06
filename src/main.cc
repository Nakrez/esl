#include <sys/time.h>
#include "parser/driver.hh"
#include "compile/compiler.hh"
#include "execute/vm.hh"
#include "utils/ro-data.hh"
#include "../lib/type/squeleton.hh"
#include "utils/option.hh"
#include <cstring>
#include <iostream>

# define BENCH 0

int main(int argc, char **argv)
{
    Driver driver;
    esl::Compiler *compiler = nullptr;

    if (argc < 2)
        return (1);
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        Option::instanciate();
        Option* instance=Option::get();

        if (arg.find("--")==0){
            std::string s=arg;
            s.erase(0,2);
            if (!s.compare("ast")) instance->set_ast(true);
            else if (!s.compare("byte")) instance->set_byte(true);
            else if (!s.compare("ee")) instance->ee_optn();
            else
                std::cerr << "Unknown option : " << s << std::endl;
        }
        else
            driver.parser(argv[i]);
            if(instance->get_ast()) instance->ast_optn(&driver);
            if(instance->get_byte()) instance->byte_optn(&driver);
    }

    /* Compile the AST given by the parser into bytecode */
    if (!driver.errors_get())
    {
        compiler = new esl::Compiler(driver.ast());

        #if BENCH == 1
            struct timeval start, end;
            long long useconds;

            gettimeofday(&start, nullptr);
        #endif /* !BENCH */

        compiler->compile();
        #if BENCH == 1
            gettimeofday(&end, nullptr);
            useconds = end.tv_usec - start.tv_usec;

            std::cout << "Compilation time : " << useconds << std::endl;
        #endif /* !BENCH */

        #if BENCH == 1
            gettimeofday(&start, nullptr);
        #endif /* !BENCH */

        try
        {
            esl::Vm::instanciate(compiler->get_bytecode());
            esl::Vm::get()->run();
        }
        catch (esl::Exception& e)
        {
            std::cerr << "ESL exception: " << e.message() << std::endl;
        }

        #if BENCH == 1
            gettimeofday(&end, nullptr);
            useconds = end.tv_usec - start.tv_usec;

            std::cout << "Execution time : " << useconds << std::endl;
        #endif /* !BENCH */

        esl::RoData::instance_delete();
    }

    driver.free();

    delete compiler;
    esl::Squeleton::free();
    esl::Vm::free();

    return (0);
}
