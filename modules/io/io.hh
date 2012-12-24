#ifndef IO_HH
# define IO_HH

#include "../../lib/extension.hh"

class Io: public esl::Extension
{
    public:
        void init ();
        esl::ContentObject* print (esl::Params*);
};

extern "C" Io* get ();
extern "C" void destroy (Io*);

#endif /* !IO_HH */
