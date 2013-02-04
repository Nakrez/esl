#ifndef DELEGATE_HH
# define DELEGATE_HH

# include "content.hh"
# include "context.hh"
# include "params.hh"

namespace esl
{
    class DelegateBase
    {
        public:
            virtual GCObject* Call(const Params&, Context*) = 0;
    };

    template <class Class> class Delegate: public DelegateBase, Content
    {
        public:
            typedef GCObject* (Class::*Function)(const Params&, Context*);
            Delegate(Class* object, Function f)
                : obj_ (object)
                , fun_ (f)
            {
            }

            virtual ~Delegate ()
            {
                delete obj_;
            }

            virtual GCObject* Call(const Params& params, Context* context)
            {
                return (obj_->*fun_)(params, context);
            }

        private:
            Class* obj_;
            Function fun_;
    };

}

#endif /* !DELEGATE_HH */
