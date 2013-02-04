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

            virtual GCObject* construct (const Params&, Context*);

            virtual GCObject* print (const Params&, Context*);
            virtual GCObject* to_string (const Params&, Context*);

            virtual GCObject* type (const Params&, Context*);

            virtual GCObject* plus_op (const Params&, Context*);
            virtual GCObject* minus_op (const Params&, Context*);
            virtual GCObject* mul_op (const Params&, Context*);
            virtual GCObject* div_op (const Params&, Context*);
            virtual GCObject* mod_op (const Params&, Context*);
            virtual GCObject* pow_op (const Params&, Context*);

            virtual GCObject* eq_op (const Params&, Context*);
            virtual GCObject* diff_op (const Params&, Context*);
            virtual GCObject* gt_op (const Params&, Context*);
            virtual GCObject* ge_op (const Params&, Context*);
            virtual GCObject* lt_op (const Params&, Context*);
            virtual GCObject* le_op (const Params&, Context*);

            virtual GCObject* and_op (const Params&, Context*);
            virtual GCObject* or_op (const Params&, Context*);

            virtual GCObject* bracket_op (const Params&, Context*);

        protected:
            void init_basics ();

            std::string name_;

            std::map<std::string,
                     std::pair<MemoryObject<esl::Content>*,
                               Visibility>> attribut_;
    };
}

#endif /* !TYPE_HH */
