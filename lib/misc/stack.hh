/// @date 06/04/2013

#ifndef STACK_HH
# define STACK_HH

# include <list>

# include <limits.hh>

# include <misc/error.hh>
# include <misc/stack-frame.hh>

namespace misc
{
    template <class T>
    class Stack
    {
        public:
            Stack();
            ~Stack();

            void pop_frame();
            void push_frame();

            void push(T* elem);

        private:
            std::list<StackFrame<T>> stack_;
    };
} // namespace misc

# include <misc/stack.hxx>

#endif /* !STACK_HH */
