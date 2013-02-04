/// @file lib/gc/memory-object.hh
/// @brief Memory object allow ESL garbrage collection
/// @author Baptiste COVOLATO <b.covolat@gmail.com>
/// @date 30/12/2012

#ifndef MEMORY_OBJECT_HH
# define MEMORY_OBJECT_HH

# include "../content.hh"

namespace esl
{
    template<class T>
    class MemoryObject
    {
        public:
            /// @brief Constructor
            /// @param data The data you want to manage
            MemoryObject (T* data);

            /// @brief Destructor (Destroy the data contained if free_ == false)
            ~MemoryObject ();

            /// @brief Increment the number of reference on the data
            void incr ();

            /// @brief Decrement the number of reference on the data
            void decr ();

            /// @brief Get the data contained by the object
            /// @return The data contained by the object
            T* data_get () const;

            /// @brief Set the data contained by the object
            /// @param data The data you want to set in the object
            void data_set (T* data);

            /// @brief Get the reference counter
            /// @return The value of the reference counter
            int count_get () const;

            /// @brief Set the reference counter value (Can be dangerous !)
            /// @param data The value you want to set as reference counter
            void count_set(int data);

            /// @brief Only delete the object, not the data contained in
            void free ();

        private:

            /// @brief The reference counter
            int count_;

            /// @brief The data contained in the object
            T* data_;

            /// @brief false if the data has to be free with the object, true
            //         else
            bool free_;
    };

    using GCObject = MemoryObject<Content>;
}

# include "memory-object.hxx"

#endif /* !MEMORY_OBJECT_HH */
