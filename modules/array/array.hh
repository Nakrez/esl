#ifndef ARRAY_MODULE_HH
# define ARRAY_MODULE_HH

#include "../../lib/extension.hh"
#include "../../lib/array.hh"

class Array: public esl::Extension
{
    public:
        void init ();
        esl::ContentObject* create (esl::Params*);
};

extern "C" Array* get ();
extern "C" void destroy (Array*);

#endif /* !ARRAY_MODULE_HH */
