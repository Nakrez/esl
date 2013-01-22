#ifndef FILE_HH
# define FILE_HH

# include <iostream>
# include <vector>

# include "../../lib/type/type.hh"
# include "../../lib/gc/memory-object.hh"
# include "../../lib/exception.hh"

namespace esl
{
    class File : public Type
    {
        public:
            File ();
            ~File ();

            virtual void init ();

            virtual MemoryObject<Content>* construct (const Params&);

            virtual MemoryObject<Content>* print (const Params&);
            virtual MemoryObject<Content>* to_string (const Params&);

            MemoryObject<Content>* open (const Params&);
            MemoryObject<Content>* close (const Params&);
    };
}

#endif /* !FILE_HH */
