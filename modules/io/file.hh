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
            MemoryObject<Content>* is_open (const Params&);
            MemoryObject<Content>* close (const Params&);

            MemoryObject<Content>* read_line (const Params&);
            MemoryObject<Content>* read_all (const Params&);

            MemoryObject<Content>* seek_beg (const Params&);
            MemoryObject<Content>* seek_end (const Params&);

            MemoryObject<Content>* eof (const Params&);

            MemoryObject<Content>* write (const Params&);
            MemoryObject<Content>* write_newline (const Params&);
    };
}

#endif /* !FILE_HH */
