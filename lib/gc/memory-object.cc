#include "memory-object.hh"

esl::MemoryObject::MemoryObject (void* data)
    : count_ (1)
    , data_ (data)
    , privacy_ (false)
{
}

esl::MemoryObject::MemoryObject (void* data, bool privacy)
    : count_ (1)
    , data_ (data)
    , privacy_ (privacy)
{
}


