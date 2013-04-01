#include <iostream>

#include <compile/libcompile.hh>
#include <command/register.hh>

int main(int argc, char **argv)
{
    try {
        command::Register::instance().parse_args(argc, argv);

        if (command::Register::instance().number_enable_command() == 0)
        {
            if (main_filename == "")
                command::Register::instance().enable_command("usage");
            else
                command::Register::instance().enable_command("-e|--execute");
        }

        command::Register::instance().execute();
        command::Register::instance().error_get().exit_on_error();
    }
    catch (misc::Error& e)
    {
        std::cerr << e;
        exit(e.error_code_get());
    }

    // FIXME
    // if (compile::main_executable)
    //     delete compile::main_executable;
}
