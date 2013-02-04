/// @file lib/type/type.hh
/// @brief Basic class that represent an ESL type (class)
/// @author Baptiste COVOLATO <b.covolato@gmail.com>
/// @date 30 Dec 2012

#ifndef TYPE_HH
# define TYPE_HH

# include <string>
# include <map>

# include "squeleton.hh"
# include "../function.hh"
# include "../content.hh"
# include "../gc/memory-object.hh"

namespace esl
{
    class Type : public Content
    {
        public:
            Type (const std::string& name);
            virtual ~Type ();

            void inherit (const std::string& type);

            virtual void init ();

            virtual std::string type_name_get() const;

            virtual GCObject* construct (const Params&);

            virtual GCObject* print (const Params&);
            virtual GCObject* to_string (const Params&);

            virtual GCObject* type (const Params&);

            virtual GCObject* plus_op (const Params&);
            virtual GCObject* minus_op (const Params&);
            virtual GCObject* mul_op (const Params&);
            virtual GCObject* div_op (const Params&);
            virtual GCObject* mod_op (const Params&);
            virtual GCObject* pow_op (const Params&);

            virtual GCObject* eq_op (const Params&);
            virtual GCObject* diff_op (const Params&);
            virtual GCObject* gt_op (const Params&);
            virtual GCObject* ge_op (const Params&);
            virtual GCObject* lt_op (const Params&);
            virtual GCObject* le_op (const Params&);

            virtual GCObject* and_op (const Params&);
            virtual GCObject* or_op (const Params&);

            virtual GCObject* bracket_op (const Params&);

        protected:
            void init_basics ();

            std::string name_;

            std::map<std::string,
                     std::pair<MemoryObject<esl::Content>*,
                               Visibility>> attribut_;
    };
}

#endif /* !TYPE_HH */
