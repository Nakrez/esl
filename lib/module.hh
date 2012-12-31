#ifndef MODULE_HH
# define MODULE_HH

# include <dlfcn.h>
# include <string>
# include <iostream>

# include "content.hh"
# include "gc/memory-object.hh"
# include "extension.hh"

namespace esl
{
    class Module : public Content
    {
        public:
            Module (const std::string&);
            ~Module ();

            void load ();
            MemoryObject<Content>* call(const std::string& name,
                                        const Params& params);

        private:
            std::string path_;
            Extension *ext_;
            EDestroy destroy_module_;
            void* lib_;
    };
}

#endif /* !MODULE_HH */
