#ifndef STACK_HH
# define STACK_HH

# include <iostream>
# include <vector>

# include "../../lib/type/type.hh"
# include "../../lib/gc/memory-object.hh"
# include "../../lib/exception.hh"

namespace esl
{
    class Stack : public Type
    {
        public:
            Stack ();
            ~Stack ();

            virtual GCObject* construct (const Params&);

            virtual void init ();

            virtual GCObject* print (const Params&);
            virtual GCObject* to_string (const Params&);

            GCObject* pop (const Params& params);
            GCObject* push (const Params& params);
            GCObject* top (const Params& params);
            GCObject* empty (const Params& params);
            GCObject* size (const Params& params);
    };
}

#endif /* !STACK_HH */
