/// @file lib/type/object.hh
/// @brief Represent an ESL object that can be instanciate in the VM
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 13 Jan 2013

#ifndef OBJECT_HH
# define OBJECT_HH

# include <map>
# include <string>

# include "squeleton.hh"
# include "../content.hh"

namespace esl
{
    class Object : public Content
    {
        public:
            Object (const std::string& type);

            MemContent call_method (const std::string& fun_name,
                                    Context* context,
                                    const Params& params);

            Function* get_method (const std::string& fun_name);

        private:
            std::string type_;

            std::map<std::string, std::pair<MemContent, Visibility>> attributs_;
    };
}

#endif /* !OBJECT_HH */
