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

            virtual GCObject* construct (const Params&, Context*);

            virtual GCObject* print (const Params&, Context*);
            virtual GCObject* to_string (const Params&, Context*);

            GCObject* open (const Params&, Context*);
            GCObject* is_open (const Params&, Context*);
            GCObject* close (const Params&, Context*);

            GCObject* read_line (const Params&, Context*);
            GCObject* read_all (const Params&, Context*);

            GCObject* seek_beg (const Params&, Context*);
            GCObject* seek_end (const Params&, Context*);

            GCObject* eof (const Params&, Context*);

            GCObject* write (const Params&, Context*);
            GCObject* write_newline (const Params&, Context*);
    };
}

#endif /* !FILE_HH */
