#ifndef OPTION_HH
#define OPTION_HH
#include <map>
#include <string>

class Driver;

class Option
{
    public:
        Option ();
        ~Option ();

        void ee_optn();
        void byte_optn(Driver* driver);
        void ast_optn(Driver* driver);
};
#endif /* OPTION_HH */
