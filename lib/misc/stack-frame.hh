/// @date 06/04/2013

#ifndef STACK_FRAME_HH
# define STACK_FRAME_HH

# include <vector>

# include <limits.hh>

# include <misc/error.hh>

namespace misc
{
    template <class T>
    class StackFrame
    {
        public:
            StackFrame();
            ~StackFrame();

            void push(T* elem);

        protected:
            std::vector<T*> frame_;
            unsigned position_;
    };
} // namespace misc

# include <misc/stack-frame.hxx>

#endif /* !STACK_FRAME_HH */
