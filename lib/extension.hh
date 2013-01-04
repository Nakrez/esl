#ifndef EXTENSION_HH
# define EXTENSION_HH

# include <string>
# include <map>

# include "delegate.hh"

namespace esl
{
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
