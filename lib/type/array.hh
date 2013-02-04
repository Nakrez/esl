#ifndef ARRAY_HH
# define ARRAY_HH

# include <iostream>
# include <vector>

# include "type.hh"
# include "../gc/memory-object.hh"
# include "../exception.hh"

namespace esl
{
    class Array : public Type
    {
        public:
            Array ();
            ~Array ();

            virtual GCObject* construct (const Params&);

            virtual void init ();

            virtual std::string type_name_get () const;

            virtual GCObject* print (const Params&);
            virtual GCObject* to_string (const Params&);

            virtual GCObject* bracket_op (const Params&);

            virtual GCObject* size (const Params&);
            virtual GCObject* at (const Params&);
            virtual GCObject* put_at (const Params&);
            virtual GCObject* push_back (const Params&);
    };
}

#endif /* !ARRAY_HH */
