#ifndef ESL_HH
# define ESL_HH

# include <iostream>

# include "../../lib/extension.hh"
# include "../../lib/type/object.hh"

# include "../../src/execute/vm.hh"

class Esl: public esl::Extension
{
    public:
        void init ();
};

extern "C" Esl* get ();
extern "C" void destroy (Esl*);

#endif /* !ESL_HH */
