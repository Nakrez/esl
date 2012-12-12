#include "parser/driver.hh"
#include "compile/compiler.hh"
#include "execute/vm.hh"

int main(int argc, char **argv)
{
    Driver    driver;
    esl::Compiler    *compiler = NULL;
    esl::Vm          *vm = NULL;

    if (argc < 2)
        return (1);

    /* Parser the file given in arg */
    driver.parser(argv[1]);

    /* Compile the AST given by the parser into bytecode */
    if (!driver.errors_get())
    {
        compiler = new esl::Compiler(driver.ast());
        compiler->compile();

        compiler->export_bytecode("byte.eslc");

        vm = new esl::Vm(compiler->get_bytecode());

        vm->run();
    }

    driver.free();

    delete compiler;
    delete vm;

    return (0);
}
