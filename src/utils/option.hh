#ifndef OPTION_HH
#define OPTION_HH
#include <map>
#include <string>

class Driver;

class Option
{
    public:
        static void instanciate ();
        static Option* get ();
        static void free ();

        void ee_optn();
        void byte_optn(Driver* driver);
        void ast_optn(Driver* driver);
        void set_ast(bool tmp);
        void set_byte(bool tmp);
        const bool get_ast() const;
        const bool get_byte() const;
    private:
        bool ast_bool;
        bool byte_bool;
        Option();
        ~Option();
        static Option* instance_;
};
#endif /* OPTION_HH */
