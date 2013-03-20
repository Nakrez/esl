#include <sys/time.h>
#include <parser/driver.hh>
#include <compile/compiler.hh>
#include <execute/vm.hh>
#include <type/squeleton.hh>
#include <ast/pretty-printer.hh>
#include <utils/option.hh>
#include <cstring>
#include <iostream>

# define BENCH 0
//# define AST_TEST

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
    }
    /* Compile the AST given by the parser into bytecode */
    else if (!driver.errors_get())
    {
        compile::Compiler compiler;

        #if BENCH == 1
            struct timeval start, end;
            long long useconds;

            gettimeofday(&start, nullptr);
        #endif /* !BENCH */

        // Compiler instanciation
        compiler(*(driver.ast_));

        /*
        if (instance->get_byte())
            instance->byte_optn(&driver);
        */

        try
        {
            /*esl::Vm::instanciate(compiler->get_bytecode());
            esl::Vm::get()->run();*/
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
