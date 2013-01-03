#ifndef DELEGATE_HH
# define DELEGATE_HH

# include "content.hh"
# include "params.hh"

namespace esl
{
    class DelegateBase
    {
        public:
            virtual MemoryObject<Content>* Call(const Params&) = 0;
    };

    template <class Class> class Delegate: public DelegateBase, Content
    {
        public:
            typedef MemoryObject<Content>* (Class::*Function)(const Params&);
            Delegate(Class* object, Function f)
                : obj_ (object)
                , fun_ (f)
            {
            }

            virtual ~Delegate ()
            {
                delete obj_;
            }

            virtual MemoryObject<Content>* Call(const Params& params)
            {
                return (obj_->*fun_)(params);
            }

        private:
            Class* obj_;
            Function fun_;
    };

}

#endif /* !DELEGATE_HH */
