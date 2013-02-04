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

            virtual GCObject* construct (const Params&, Context*);

            virtual void init ();

            virtual GCObject* print (const Params&, Context*);
            virtual GCObject* to_string (const Params&, Context*);

            GCObject* pop (const Params& params, Context*);
            GCObject* push (const Params& params, Context*);
            GCObject* top (const Params& params, Context*);
            GCObject* empty (const Params& params, Context*);
            GCObject* size (const Params& params, Context*);
    };
}

#endif /* !STACK_HH */
