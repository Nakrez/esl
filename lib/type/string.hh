#ifndef STRING_HH
# define STRING_HH

# include <iostream>
# include <string>
# include <sstream>

# include "type.hh"

namespace esl
{
    class String : public Type
    {
        public:
            String ();
            ~String ();

            virtual std::string type_name_get () const;

            virtual void init ();

            virtual MemoryObject<Content>* size (const Params&);
            virtual MemoryObject<Content>* at (const Params&);
            virtual MemoryObject<Content>* split (const Params&);

            virtual MemoryObject<Content>* construct (const Params&);

            virtual MemoryObject<Content>* print (const Params&);
            virtual MemoryObject<Content>* to_string (const Params&);

            virtual MemoryObject<Content>* plus_op (const Params&);

            virtual MemoryObject<Content>* eq_op (const Params&);
            virtual MemoryObject<Content>* diff_op (const Params&);
            virtual MemoryObject<Content>* gt_op (const Params&);
            virtual MemoryObject<Content>* ge_op (const Params&);
            virtual MemoryObject<Content>* lt_op (const Params&);
            virtual MemoryObject<Content>* le_op (const Params&);
    };
}

#endif /* !STRING_HH */
