#ifndef OBJECT_HH
# define OBJECT_HH

# include <iostream>

namespace esl
{
    class Object
    {
        public:
            Object ();

            void incr_ref ();
            void decr_ref ();

        protected:
            int ref_count_;
    };
}

#endif /* !OBJECT_HH */
