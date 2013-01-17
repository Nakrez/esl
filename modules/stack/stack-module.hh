#ifndef ARRAY_MODULE_HH
# define ARRAY_MODULE_HH

# include "../../lib/extension.hh"
# include "../../lib/type/int-object.hh"

# include "stack.hh"
# include "stack-object.hh"

class ArrayModule: public esl::Extension
{
    public:
        void init ();
};

extern "C" ArrayModule* get ();
extern "C" void destroy (ArrayModule*);

#endif /* !ARRAY_MODULE_HH */
