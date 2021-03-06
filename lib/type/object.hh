/// @file lib/type/object.hh
/// @brief Represent an ESL object that can be instanciate in the VM
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 13 Jan 2013

#ifndef OBJECT_HH
# define OBJECT_HH

# include <unordered_map>
# include <string>

# include "squeleton.hh"
# include "../content.hh"

namespace esl
{
    class Object : public Content
    {
        public:
            Object (const std::string& type);
            ~Object ();

            GCObject* call_method (const std::string& fun_name,
                                   Context* context,
                                   const Params& params);

            Function* get_method (const std::string& fun_name);

            void update_attribut (const std::string& attr_name,
                                  GCObject* value);

            GCObject* attribut_get (const std::string& attr_name);

            const std::string& type_get() const;

        private:
            void register_attribut (const std::unordered_map<std::string,
                                                             Visibility>& attr);

            std::string type_;
            std::unordered_map<std::string,
                               std::pair<GCObject*, Visibility>> attributs_;
    };
}

#endif /* !OBJECT_HH */
