#ifndef EXECUTABLE_CONTEXT_HH
# define EXECUTABLE_CONTEXT_HH

# include "runtime.hh"

namespace esl
{
    class ExecutableContext : public Runtime
    {
        public:
            ExecutableContext ();
            ~ExecutableContext ();
    };
}

#endif /* !EXECUTABLE_CONTEXT_HH */
