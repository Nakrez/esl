#ifndef ARRAY_OBJECT_HH
# define ARRAY_OBJECT_HH

# include <vector>

# include "../../lib/type/object.hh"
# include "../../lib/gc/memory-object.hh"
# include "../../lib/content.hh"
# include "../../lib/exception.hh"

namespace esl
{
    class ArrayObject : public Object
    {
        public:
            ArrayObject ();
            ArrayObject (int size);
            ~ArrayObject ();

            MemoryObject<Content>* at (int i);

        private:
            std::vector<MemoryObject<Content>*> data_;
    };
}

#endif /* !ARRAY_OBJECT_HH */
