/// @file lib/type/squeleton.hh
/// @brief Contains and deal with all type in the running program.
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 12 Jan 2013

#ifndef SQUELETON_HH
# define SQUELETON_HH

# include <unordered_map>
# include <string>
# include <iostream>

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
    using Method = std::pair<esl::MemoryObject<Function>*, Visibility>;
    using Methods = std::unordered_map<std::string, Method>;

    using Attribut = std::pair<std::string, Visibility>;
    using Attributs = std::unordered_map<std::string, Visibility>;//Attribut>;

    class Type;

    class Squeleton
    {
        Squeleton(const Squeleton&) = delete;
        public:
            static Squeleton& get();

            void inherit (const std::string& type, const std::string& inherit);

            void register_type (const std::string& name, Type* ptr);

            Function* method_get (const std::string& type,
                                  const std::string& name);

            void register_method (const std::string& type,
                                  const std::string& name,
                                  Function* fun);

            void register_attribut (const std::string& type,
                                    const std::string& name);

            const Attributs& attributs_get (const std::string& type);

            bool has_attribut(const std::string& type);

            bool type_attribut(const std::string& type,
                               const std::string& attribut);
            bool type_method(const std::string& type,
                             const std::string& method);
            bool type_exist(const std::string& type);

        private:
            Squeleton ();
            ~Squeleton ();

            void type_existance (const std::string&);

            std::unordered_map<std::string, Methods> object_methods_;
            std::unordered_map<std::string, Attributs> object_attributs_;
            std::unordered_map<std::string, Type*> declared_type_;

            static Squeleton* instance_;
    };
}
#endif /* !SQUELETON_HH */
