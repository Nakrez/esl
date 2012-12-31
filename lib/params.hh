#ifndef ESL_PARAMS_HH
# define ESL_PARAMS_HH

# include <deque>

# include "content.hh"
# include "gc/memory-object.hh"

namespace esl
{
    class Params
    {
        public:
            Params ();
            ~Params ();

            bool empty () const;
            int count () const;
            MemoryObject<Content>* get_params (int) const;
            void params_set (MemoryObject<Content>*);

        private:
            std::deque<MemoryObject<Content>*> params_;
    };
}

#endif /* !ESL_PARAMS_HH */
