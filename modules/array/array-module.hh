#ifndef ARRAY_MODULE_HH
# define ARRAY_MODULE_HH

# include "../../lib/extension.hh"
# include "../../lib/type/int-object.hh"

# include "array.hh"
# include "array-object.hh"

class ArrayModule: public esl::Extension
{
    public:
        void init ();
};

extern "C" ArrayModule* get ();
extern "C" void destroy (ArrayModule*);

#endif /* !ARRAY_MODULE_HH */
