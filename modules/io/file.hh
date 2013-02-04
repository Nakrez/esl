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

            virtual GCObject* construct (const Params&);

            virtual GCObject* print (const Params&);
            virtual GCObject* to_string (const Params&);

            GCObject* open (const Params&);
            GCObject* is_open (const Params&);
            GCObject* close (const Params&);

            GCObject* read_line (const Params&);
            GCObject* read_all (const Params&);

            GCObject* seek_beg (const Params&);
            GCObject* seek_end (const Params&);

            GCObject* eof (const Params&);

            GCObject* write (const Params&);
            GCObject* write_newline (const Params&);
    };
}

#endif /* !FILE_HH */
