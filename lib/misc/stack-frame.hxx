#ifndef STACK_FRAME_HXX
# define STACK_FRAME_HXX

# include <misc/stack-frame.hh>

namespace misc
{
    template <class T>
    StackFrame<T>::StackFrame()
        : frame_(std::vector<T*>(STACK_FRAME_MAX_SIZE, nullptr))
        , position_(0)
    {}

    template <class T>
    StackFrame<T>::~StackFrame()
    {}

    template <class T>
    void StackFrame<T>::push(T* elem)
    {
        if (position_ == STACK_FRAME_MAX_SIZE)
            (misc::Error() << misc::Error::EXEC
                          << "Frame size overextended"
                          << std::endl).exit_on_error();
        frame_[position_++] = elem;
    }
} // namespace misc

#endif /* !STACK_FRAME_HXX */
