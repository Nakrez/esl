#ifndef ARRAY_OBJECT_HH
# define ARRAY_OBJECT_HH

# include <stack>

# include "../../lib/type/object.hh"
# include "../../lib/gc/memory-object.hh"
# include "../../lib/content.hh"
# include "../../lib/exception.hh"

namespace esl
{
    class StackObject : public Object
    {
        public:
            StackObject ();
            ~StackObject ();

            int size () const;
            int empty () const;

            void pop ();
            void push (MemoryObject<Content>* obj);
            MemoryObject<Content>* top () const;

        private:
            std::stack<MemoryObject<Content>*> data_;
    };
}

#endif /* !ARRAY_OBJECT_HH */
