#ifndef ARRAY_HH
# define ARRAY_HH

# include <iostream>
# include <vector>

# include "type.hh"
# include "int.hh"
# include "../gc/memory-object.hh"
# include "../exception.hh"

namespace esl
{
    class Array : public Type
    {
        public:
            Array (unsigned int size);
            ~Array ();

            static MemoryObject<Content>* instanciate ();
            virtual MemoryObject<Content>* print (const Params&);
            virtual std::string type_name_get () const;

            esl::MemoryObject<esl::Content>* at (unsigned int);

        private:
            std::vector<esl::MemoryObject<esl::Content>*> data_;
    };
}

#endif /* !ARRAY_HH */
