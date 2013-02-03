#ifndef ARRAY_HH
# define ARRAY_HH

# include <iostream>
# include <vector>

# include "../../lib/type/type.hh"
# include "../../lib/gc/memory-object.hh"
# include "../../lib/exception.hh"

namespace esl
{
    class Array : public Type
    {
        public:
            Array ();
            ~Array ();

            virtual MemoryObject<Content>* construct (const Params&);

            virtual void init ();

            virtual std::string type_name_get () const;

            virtual MemoryObject<Content>* print (const Params&);
            virtual MemoryObject<Content>* to_string (const Params&);

            virtual MemoryObject<Content>* bracket_op (const Params&);

            virtual MemoryObject<Content>* size (const Params&);
            virtual MemoryObject<Content>* at (const Params&);
            virtual MemoryObject<Content>* put_at (const Params&);
    };
}

#endif /* !ARRAY_HH */
