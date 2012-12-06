#ifndef CONTENT_OBJECT_HH
# define CONTENT_OBJECT_HH

# include "object.hh"

enum obj_type
{
    O_NIL,
    O_FUNCTION,
    O_VALUE,
    O_INT,
    O_STRING,
    O_RUNTIME
};

namespace esl
{
    class ContentObject : public Object
    {
        public:
            ContentObject ();
            ContentObject (obj_type, void*);
            ~ContentObject ();

            void* content_get () const;
            obj_type type_get () const;

            void content_set (void* content);

        protected:
            obj_type type_;
            void* content_;

    };
}
#endif /* !CONTENT_OBJECT_HH */
