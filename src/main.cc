#include <iostream>

#include <exception.hh>
#include <type/squeleton.hh>

#include <parser/driver.hh>
#include <compile/compiler.hh>
#include <execute/vm.hh>
#include <ast/pretty-printer.hh>
#include <utils/option.hh>
#include <execute/executable-dumper.hh>

int main(int argc, char **argv)
{
    Driver driver;

    Option::instanciate();

    Option* instance = Option::get();

    if (argc < 2)
        return (1);
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        if (!arg.find("--"))
        {
            std::string s=arg;
            s.erase(0,2);
            if (!s.compare("ast"))
                instance->set_ast(true);
            else if (!s.compare("byte"))
                instance->set_byte(true);
            else if (!s.compare("ee"))
                instance->ee_optn();
            else
                std::cerr << "Unknown option : " << s << std::endl;
        }
        else
            // FIXME : replace that with wrapper in Driver
            driver.ast_ = driver.parser(argv[i]);
    }

    if (!driver.errors_get() && instance->get_ast())
    {
        ast::PrettyPrinter print(std::cout);
        print(*driver.ast_);
        std::cout << std::endl;
        exit(0); // FIXME
    }
    /* Compile the AST given by the parser into bytecode */
    else if (!driver.errors_get())
    {
        compile::Compiler compiler;

        // Compiler instanciation
        compiler(*(driver.ast_));

        if (instance->get_byte())
        {
            execute::ExecutableDumper dumper(std::cout);
            dumper.dump(compiler.exec_get());
            exit(0); // FIXME
        }

        try
        {
            execute::Vm vm = execute::Vm(compiler.exec_get());
            vm.run();
        }
        catch (esl::Exception& e)
        {
            std::cerr << "ESL exception: " << e.message() << std::endl;
        }
    }

    esl::Squeleton::free();
    //esl::Vm::free();

    return (0);
}
