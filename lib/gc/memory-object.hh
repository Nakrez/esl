#ifndef MEMORY_OBJECT_HH
# define MEMORY_OBJECT_HH

namespace esl
{
    template<class T>
    class MemoryObject
    {
        public:
            MemoryObject (T*);
            MemoryObject (T*, bool);
            ~MemoryObject ();

            void incr ();
            void decr ();

            T* data_get () const;
            void data_set (T*);

            void free ();
        private:
            int count_;
            T* data_;
            bool privacy_;
            bool free_;
    };
}

# include "memory-object.hxx"

#endif /* !MEMORY_OBJECT_HH */
