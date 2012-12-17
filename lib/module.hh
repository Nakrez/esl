#ifndef MODULE_HH
# define MODULE_HH

# include <dlfcn.h>
# include <string>

# include "extension.hh"

namespace esl
{
    class Module
    {
        public:
            Module (const std::string&);
            ~Module ();

            void load ();
            ContentObject* call(const std::string& name, esl::Params* params);

        private:
            std::string path_;
            Extension *ext_;
            EDestroy destroy_module_;
            void* lib_;
    };
}

#endif /* !MODULE_HH */
