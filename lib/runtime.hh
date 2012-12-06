#ifndef RUNTIME_HH
# define RUNTIME_HH

# include "context.hh"

namespace esl
{
    class Runtime : public Context
    {
        public:
            Runtime();
            ~Runtime();

        private:
            int pc_;
    };
}

#endif /* !RUNTIME_HH */
