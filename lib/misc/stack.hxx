#ifndef STACK_HXX
# define STACK_HXX

# include <misc/stack.hh>

namespace misc
{
    template <class T>
    Stack<T>::Stack()
    {}

    template <class T>
    Stack<T>::~Stack()
    {}

    template <class T>
    inline void Stack<T>::pop_frame()
    {
        if (stack_.size())
            stack_.pop_front();
    }

    template <class T>
    inline void Stack<T>::push_frame()
    {
        stack_.push_front(StackFrame<T>());
    }

    template <class T>
    inline void Stack<T>::push(T* elem)
    {
        stack_.front().push(elem);
    }
} // namespace misc

#endif /* !STACK_HXX */
