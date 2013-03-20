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
        void set_ast(bool tmp);
        void set_byte(bool tmp);
        bool get_ast() const;
        bool get_byte() const;
    private:
        bool ast_bool;
        bool byte_bool;
        Option();
        ~Option();
        static Option* instance_;
};
#endif /* OPTION_HH */
