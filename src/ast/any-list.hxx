#ifndef ANY_LIST_HXX
# define ANY_LIST_HXX

# include <ast/any-list.hh>

namespace ast
{
    template<class T>
    AnyList<T>::AnyList(const yy::location& location)
        : Ast(location)
    {}

    template<class T>
    AnyList<T>::AnyList(const yy::location& location, T* elem)
        : Ast(location)
    {
        list_.push_back(elem);
    }

    template <class T>
    AnyList<T>::~AnyList()
    {
        for (auto elem : list_)
            delete elem;
    }

    template <class T>
    const std::list<T*>& AnyList<T>::list_get() const
    {
        return list_;
    }

    template <class T>
    inline void AnyList<T>::push_back(T* elem)
    {
        list_.push_back(elem);
    }

    template <class T>
    inline void AnyList<T>::accept(Visitor& visitor)
    {
        visitor(*this);
    }
} // namespace ast

#endif /* !ANY_LIST_HXX */
