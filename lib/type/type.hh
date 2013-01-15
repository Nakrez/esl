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

            void init_basics ();
            virtual void init ();

            virtual std::string type_name_get() const;

            virtual MemoryObject<Content>* construct (const Params&);

            virtual MemoryObject<Content>* print (const Params&);
            virtual MemoryObject<Content>* to_string (const Params&);

            virtual MemoryObject<Content>* plus_op (const Params&);
            virtual MemoryObject<Content>* minus_op (const Params&);
            virtual MemoryObject<Content>* mul_op (const Params&);
            virtual MemoryObject<Content>* div_op (const Params&);
            virtual MemoryObject<Content>* mod_op (const Params&);
            virtual MemoryObject<Content>* pow_op (const Params&);

            virtual MemoryObject<Content>* eq_op (const Params&);
            virtual MemoryObject<Content>* diff_op (const Params&);
            virtual MemoryObject<Content>* gt_op (const Params&);
            virtual MemoryObject<Content>* ge_op (const Params&);
            virtual MemoryObject<Content>* lt_op (const Params&);
            virtual MemoryObject<Content>* le_op (const Params&);

            virtual MemoryObject<Content>* and_op (const Params&);
            virtual MemoryObject<Content>* or_op (const Params&);

            virtual MemoryObject<Content>* bracket_op (const Params&);

        protected:
            std::string name_;

            std::map<std::string,
                     std::pair<MemoryObject<esl::Content>*,
                               Visibility>> attribut_;
    };
}

#endif /* !TYPE_HH */
