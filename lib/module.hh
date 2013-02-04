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
            Module (const std::string&, const std::string&);
            ~Module ();

            bool is_registered (const std::string&) const;
            const std::string& name_get () const;
            void load ();
            GCObject* call(const std::string& name,
                           const Params& params,
                           Context* context);

        private:
            std::string path_;
            std::string name_;
            Extension *ext_;
            EDestroy destroy_module_;
            void* lib_;
    };
}

#endif /* !MODULE_HH */
