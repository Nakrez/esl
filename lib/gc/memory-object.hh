#ifndef MEMORY_OBJECT_HH
# define MEMORY_OBJECT_HH

namespace esl
{
    class MemoryObject
    {
        public:
            MemoryObject (void*);
            MemoryObject (void*, bool);

            void incr ();
            void decr ();

        private:
            int count_;
            void* data_;
            bool privacy_;
    };
}

#endif /* !MEMORY_OBJECT_HH */
