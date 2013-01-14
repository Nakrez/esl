#ifndef IO_HH
# define IO_HH

# include <iostream>

# include "../../lib/extension.hh"
# include "../../lib/type/object.hh"

# include "../../src/execute/vm.hh"

class Io: public esl::Extension
{
    public:
        void init ();
        esl::MemoryObject<esl::Content>* print (const esl::Params&);
};

extern "C" Io* get ();
extern "C" void destroy (Io*);

#endif /* !IO_HH */
