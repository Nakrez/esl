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

            virtual MemoryObject<Content>* print (const Params&);
            virtual std::string type_name_get () const;

            int data_get () const;
            void data_set (int data);

        private:
            int data_;
    };
}

#endif /* !INT_HH */
