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

            virtual MemoryObject<Content>* plus_op (const Params&);
            virtual MemoryObject<Content>* minus_op (const Params&);
            virtual MemoryObject<Content>* mul_op (const Params&);
            virtual MemoryObject<Content>* div_op (const Params&);
            virtual MemoryObject<Content>* mod_op (const Params&);

            int data_get () const;
            void data_set (int data);

        private:
            int data_;
    };
}

#endif /* !INT_HH */
