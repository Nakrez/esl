#ifndef EXTENSION_HH
# define EXTENSION_HH

# include <string>
# include <map>

# include "content-object.hh"
# include "params.hh"

namespace esl
{
    class DelegateBase
    {
        public:
            virtual ContentObject* Call(Params*) = 0;
    };

    template <class Class> class Delegate: public DelegateBase
    {
        public:
            typedef ContentObject* (Class::*Function)(Params*);
            Delegate(Class* object, Function f)
                : obj_ (object)
                , fun_ (f)
            {
            }

            virtual ~Delegate ()
            {
                delete obj_;
            }

            virtual ContentObject* Call(Params* params)
            {
                return (obj_->*fun_)(params);
            }

        private:
            Class* obj_;
            Function fun_;
    };

    class Extension
    {
        public:
            Extension ();
            virtual ~Extension ();

            virtual void init () = 0;

            ContentObject* call(const std::string&, Params*);

        protected:
            void register_function (const std::string&, DelegateBase*);

        private:
            std::map<std::string, DelegateBase*> functions_;
    };

    using EGet = Extension* (*)();
    using EDestroy = void (*)(Extension*);
}
#endif /* !EXTENSION_HH */
