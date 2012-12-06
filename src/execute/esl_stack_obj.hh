#ifndef STACK_OBJ_HH
# define STACK_OBJ_HH

# include "../../lin/content-object.hh"

namespace esl
{
    class StackObject : public ContextObject
    {
        public:
            StackObject();
            StackObject(obj_type type, void *object);
            ~StackObject();

        private:
    };
}
#endif /* !STACK_OBJ_HH */
