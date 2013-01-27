#ifndef EXTENSION_HH
# define EXTENSION_HH

# include <string>
# include <unordered_map>

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

            bool is_registered (const std::string& name) const;

        protected:
            void register_function (const std::string&, DelegateBase*);

        private:
            std::unordered_map<std::string, DelegateBase*> functions_;
    };

    using EGet = Extension* (*)();
    using EDestroy = void (*)(Extension*);
}
#endif /* !EXTENSION_HH */
