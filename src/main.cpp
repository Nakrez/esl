#include <parser/eslxx_driver.hh>
#include <compile/esl_compiler.hh>
#include <execute/esl_vm.hh>

int main(int argc, char **argv)
{
    eslxx_driver    driver;
    esl_compiler    *compiler = NULL;
    esl_vm          *vm = NULL;

    if (argc < 2)
        return (1);

    /* Parser the file given in arg */
    driver.parser(argv[1]);

    /* Compile the AST given by the parser into bytecode */
    compiler = new esl_compiler(driver.ast());
    compiler->compile();

    compiler->export_bytecode("byte.eslc");

    vm = new esl_vm(compiler->get_bytecode());

    vm->run();

    driver.free();

    delete compiler;
    delete vm;

    return (0);
}
