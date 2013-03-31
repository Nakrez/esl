#include <other/command.hh>

namespace other
{
    void help()
    {

    }

    void usage()
    {
        std::cout << program_name << " [OPTIONS] INPUT-FILE" << std::endl;
        std::cout << "Try " << program_name << " -h or "
                  << program_name << " --help for more informations"
                  << std::endl;
    }
} // namespace other
