#ifndef CONTENT_OBJECT_HH
# define CONTENT_OBJECT_HH

# include <memory>

enum obj_type
{
    O_NIL,
    O_FUNCTION,
    O_VALUE,
    O_INT,
    O_STRING,
    O_ARRAY,
    O_PRIVATE_DATA,
    O_RUNTIME
};

namespace esl
{
    class ContentObject
    {
        public:
            ContentObject ();
            ContentObject (obj_type, void*);
            ~ContentObject ();

            void* content_get () const;
            obj_type type_get () const;

            void content_set (void* content);
            void type_set (obj_type);

        protected:
            obj_type type_;
            std::shared_ptr<void> content_;
            bool null;

    };
}
#endif /* !CONTENT_OBJECT_HH */
