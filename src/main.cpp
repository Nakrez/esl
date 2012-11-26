#include <eslxx_driver.hh>

int main(int argc, char **argv)
{
    eslxx_driver driver;

    driver.parser(argv[1]);

    driver.free();

    return (0);
}

