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

            virtual GCObject* construct (const Params&, Context*);

            virtual void init ();

            virtual std::string type_name_get () const;

            virtual GCObject* print (const Params&, Context*);
            virtual GCObject* to_string (const Params&, Context*);

            virtual GCObject* bracket_op (const Params&, Context*);

            virtual GCObject* size (const Params&, Context*);
            virtual GCObject* at (const Params&, Context*);
            virtual GCObject* put_at (const Params&, Context*);
            virtual GCObject* push_back (const Params&, Context*);
    };
}

#endif /* !ARRAY_HH */
