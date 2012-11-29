#include <parser/eslxx_driver.hh>

int main(int argc, char **argv)
{
    eslxx_driver driver;

    driver.parser(argv[1]);

    std::cout << argv[1] << std::endl;
    driver.free();

    return (0);
}
