#ifndef INT_OBJECT_HH
# define INT_OBJECT_HH

# include "object.hh"

namespace esl
{
    class IntObject : public Object
    {
        public:
            IntObject (int data);

            int data_get () const;
            void data_set (int data);

        private:
            int data_;
    };
}

#endif /* !INT_OBJECT_HH */
