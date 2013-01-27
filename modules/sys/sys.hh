#ifndef SYS_HH
# define SYS_HH

# include <iostream>

# include "../../lib/extension.hh"
# include "../../lib/type/object.hh"

# include "../../src/execute/vm.hh"

class Sys : public esl::Extension
{
    public:
        void init ();
};

extern "C" Sys* get ();
extern "C" void destroy (Sys*);

#endif /* !SYS_HH */
