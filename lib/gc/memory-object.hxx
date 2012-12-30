template<class T>
esl::MemoryObject<T>::MemoryObject (T* data)
    : count_ (1)
    , data_ (data)
    , privacy_ (false)
{

}

template<class T>
esl::MemoryObject<T>::MemoryObject (T* data, bool privacy)
    : count_ (1)
    , data_ (data)
    , privacy_ (privacy)
{

}

template<class T>
esl::MemoryObject<T>::~MemoryObject ()
{
    delete data_;
}

template<class T>
void esl::MemoryObject<T>::incr ()
{
    ++count_;
}

template<class T>
void esl::MemoryObject<T>::decr ()
{
    --count_;

    if (count_ <= 0)
        delete this;
}

template<class T>
T* esl::MemoryObject<T>::data_get () const
{
    return data_;
}

template<class T>
void esl::MemoryObject<T>::data_set (T* data)
{
    data_ = data;
}
