#ifndef EXTENSION_HH
# define EXTENSION_HH

# include <string>
# include <map>

# include "params.hh"

namespace esl
{
    class DelegateBase
    {
        public:
            virtual MemoryObject<Content>* Call(const Params&) = 0;
    };

    template <class Class> class Delegate: public DelegateBase
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

    class Extension
    {
        public:
            Extension ();
            virtual ~Extension ();

            virtual void init () = 0;

            MemoryObject<Content>* call(const std::string&,
                                        const Params&);

        protected:
            void register_function (const std::string&, DelegateBase*);

        private:
            std::map<std::string, DelegateBase*> functions_;
    };

    using EGet = Extension* (*)();
    using EDestroy = void (*)(Extension*);
}
#endif /* !EXTENSION_HH */
