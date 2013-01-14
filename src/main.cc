#include <sys/time.h>
#include "parser/driver.hh"
#include "compile/compiler.hh"
#include "execute/vm.hh"
#include "utils/ro-data.hh"
#include <cstring>
#include <iostream>

# define BENCH 0

int main(int argc, char **argv)
{
    Driver driver;
    esl::Compiler *compiler = nullptr;
    esl::Vm *vm = nullptr;

    if (argc < 2)
        return (1);
    for(int i=1; i<argc; i++){
        std::string arg=argv[i];
	if(arg.find("--")==0){
            std::cout << "PARAM:" << arg << std::endl;
            driver.parser(argv[i], "param");
        }else{
            driver.parser(argv[i], "file");
	}
    }

    /* Compile the AST given by the parser into bytecode */
    if (!driver.errors_get())
    {
        compiler = new esl::Compiler(driver.ast());

        #if BENCH == 1
            struct timeval start, end;
            long useconds;

            gettimeofday(&start, nullptr);
        #endif /* !BENCH */

        compiler->compile();

        #if BENCH == 1
            gettimeofday(&end, nullptr);
            useconds = end.tv_usec - start.tv_usec;

            std::cout << "Compilation time : " << useconds << std::endl;
        #endif /* !BENCH */

        compiler->export_bytecode("byte.eslc");

        vm = new esl::Vm(compiler->get_bytecode());

        try
        {
            vm->run();
        }
        catch (esl::Exception& e)
        {
            std::cerr << "ESL exception: " << e.message() << std::endl;
        }

        esl::RoData::instance_delete();
    }

    driver.free();

    delete compiler;
    delete vm;

    return (0);
}
