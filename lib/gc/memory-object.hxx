template<class T>
esl::MemoryObject<T>::MemoryObject (T* data)
    : count_ (1)
    , data_ (data)
    , privacy_ (false)
    , free_ (false)
{

}

template<class T>
esl::MemoryObject<T>::MemoryObject (T* data, bool privacy)
    : count_ (1)
    , data_ (data)
    , privacy_ (privacy)
    , free_ (false)
{

}

template<class T>
esl::MemoryObject<T>::~MemoryObject ()
{
    if (!free_)
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

template<class T>
void esl::MemoryObject<T>::free ()
{
    free_ = true;
    delete this;
}

template<class T>
int esl::MemoryObject<T>::count_get () const
{
    return count_;
}

template<class T>
void esl::MemoryObject<T>::count_set (int data)
{
    count_ = data;
}

