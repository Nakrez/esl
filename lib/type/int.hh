#ifndef INT_HH
# define INT_HH

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

        private:
            int data_;
    };
}

#endif /* !INT_HH */
