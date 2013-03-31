#include <other/command.hh>

namespace other
{
    void help()
    {
        version();

        std::cout << std::endl
                  << program_name << " [OPTIONS] INPUT-FILE" << std::endl;

        std::cout << "Options:" << std::endl;

        for (auto com : command::Register::instance().commands_get())
        {
            if (com.second->opts_get()[0] == '-')
            {
                std::cout << "  " << com.second->opts_get()
                          << "  " << com.second->descr_get() << std::endl;
            }
        }
    }

    void version()
    {
        std::cout << "ESL - Easy Script Language " << MAJOR_VERSION << "."
                  << MINOR_VERSION
                  << "." << DEBUG_VERSION << " (compiled " << __TIMESTAMP__
                  << ")" << std::endl;
    }

    void usage()
    {
        std::cout << program_name << " [OPTIONS] INPUT-FILE" << std::endl;
        std::cout << "Try " << program_name << " -h or "
                  << program_name << " --help for more informations"
                  << std::endl;
    }
} // namespace other
