#ifndef MODULE_HH
# define MODULE_HH

# include "runtime.hh"

namespace esl
{
    class Module : public Runtime
    {
        public:
            Module ();
            ~Module ();
    };
}

#endif /* !MODULE_HH */
