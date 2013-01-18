#ifndef STACK_MODULE_HH
# define STACK_MODULE_HH

# include "../../lib/extension.hh"

# include "stack.hh"
# include "stack-object.hh"

class StackModule: public esl::Extension
{
    public:
        void init ();
};

extern "C" StackModule* get ();
extern "C" void destroy (StackModule*);

#endif /* !STACK_MODULE_HH */
