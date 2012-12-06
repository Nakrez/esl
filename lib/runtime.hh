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

            size_t pc_get () const;
            void pc_incr (int incr);

        private:
            size_t pc_;
    };
}

#endif /* !RUNTIME_HH */
