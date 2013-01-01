#ifndef INT_HH
# define INT_HH

# include <iostream>

# include "type.hh"

namespace esl
{
    class Int : public Type
    {
        public:
            Int (int data);
            ~Int ();

            int data_get () const;
            void data_set (int data);

            virtual void print () const;
        private:
            int data_;
    };
}

#endif /* !INT_HH */
