#ifndef IO_HH
# define IO_HH

# include <iostream>

# include "../../lib/type/esl-types.hh"
# include "../../lib/extension.hh"

class Io: public esl::Extension
{
    public:
        void init ();
        esl::MemoryObject<esl::Content>* print (const esl::Params&);
};

extern "C" Io* get ();
extern "C" void destroy (Io*);

#endif /* !IO_HH */
