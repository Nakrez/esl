#include <sys/time.h>
#include <parser/driver.hh>
#include <compile/compiler.hh>
#include <execute/vm.hh>
#include <utils/ro-data.hh>
#include <type/squeleton.hh>
#include <ast/pretty-printer.hh>
#include <cstring>
#include <iostream>

# define BENCH 0
# define AST_TEST

int main(int argc, char **argv)
{
    Driver driver;
    esl::Compiler *compiler = nullptr;

    if (argc < 2)
        return (1);
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg.find("--")==0)
            driver.parser(argv[i], "param");
        else
            driver.parser(argv[i], "file");
    }

    /* Compile the AST given by the parser into bytecode */
    if (!driver.errors_get())
    {
        #ifdef AST_TEST
        ast::PrettyPrinter print(std::cout);
        print(*driver.ast_);
        #else
        compiler = new esl::Compiler(driver.ast());

        #if BENCH == 1
            struct timeval start, end;
            long long useconds;

            gettimeofday(&start, nullptr);
        #endif /* !BENCH */

        compiler->compile();
        if (driver.get_byte())
            compiler->export_bytecode("byte.eslc");
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
        delete compiler;
        #endif
    }

    //driver.free();

    esl::Squeleton::free();
    esl::Vm::free();

    return (0);
}
