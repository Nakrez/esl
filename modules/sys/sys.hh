#ifndef SYS_HH
# define SYS_HH

# include <iostream>

# include "../../lib/extension.hh"
# include "../../lib/type/object.hh"

# include "../../src/execute/vm.hh"

#include <unistd.h>

class Sys : public esl::Extension
{
    public:
        void init ();

        esl::MemoryObject<esl::Content>* fork_fun (const esl::Params&);
        esl::MemoryObject<esl::Content>* exit_fun (const esl::Params&);
};

extern "C" Sys* get ();
extern "C" void destroy (Sys*);

#endif /* !SYS_HH */
