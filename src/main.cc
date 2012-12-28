#include <sys/time.h>
#include "parser/driver.hh"
#include "compile/compiler.hh"
#include "execute/vm.hh"
#include "utils/ro-data.hh"

# define BENCH 0

int main(int argc, char **argv)
{
    Driver    driver;
    esl::Compiler    *compiler = nullptr;
    esl::Vm          *vm = nullptr;

    if (argc < 2)
        return (1);

    /* Parser the file given in arg */
    driver.parser(argv[1]);

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

        vm->run();

        esl::RoData::instance_delete();
    }

    driver.free();

    delete compiler;
    delete vm;

    return (0);
}
