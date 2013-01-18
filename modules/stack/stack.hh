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

            virtual MemoryObject<Content>* construct (const Params&);

            virtual void init ();

            virtual MemoryObject<Content>* print (const Params&);
            virtual MemoryObject<Content>* to_string (const Params&);

            MemoryObject<Content>* pop (const Params& params);
            MemoryObject<Content>* push (const Params& params);
            MemoryObject<Content>* top (const Params& params);
            MemoryObject<Content>* empty (const Params& params);
            MemoryObject<Content>* size (const Params& params);
    };
}

#endif /* !STACK_HH */
