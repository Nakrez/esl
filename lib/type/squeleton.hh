/// @file lib/type/squeleton.hh
/// @brief Contains and deal with all type in the running program.
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 12 Jan 2013

#ifndef SQUELETON_HH
# define SQUELETON_HH

# include <map>
# include <string>

# include "../exception.hh"
# include "../delegate.hh"
# include "../function.hh"

enum Visibility
{
    PUBLIC,
    PROTECTED,
    PRIVATE
};

namespace esl
{
    using Method = std::pair<Function*, Visibility>;
    using Methods = std::map<std::string, Method>;

    using Attribut = std::pair<std::string, Visibility>;
    using Attributs = std::map<std::string, Attribut>;

    class Type;

    class Squeleton
    {
        public:
            static Squeleton* get();
            static void free();

            void register_type (const std::string& name, Type* ptr);

            Function* method_get (const std::string& type,
                                  const std::string& name);

            void register_method (const std::string& type,
                                  const std::string& name,
                                  Function* fun);

            void register_attribut

            //Attributs* attributs_get (const std::string& type);

        private:
            Squeleton ();
            ~Squeleton ();

            void type_existance (const std::string&);

            std::map<std::string, Methods> object_methods_;
            std::map<std::string, Attributs> object_attributs_;
            std::map<std::string, Type*> declared_type_;

            static Squeleton* instance_;
    };
}
#endif /* !SQUELETON_HH */
