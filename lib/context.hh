#ifndef CONTEXT_H_
# define CONTEXT_H_

# include <string>
# include <map>
# include <memory>

# include "module.hh"
# include "content.hh"

namespace esl
{
    class Params;
    class Runtime;

    using Callback = MemoryObject<Content>* (*)(Runtime*, const Params&);
    using ModulePtr = std::shared_ptr<Module>;
    using VarContent = MemoryObject<Content>*;

    MemoryObject<Content>* std_callback (Runtime*, const Params&);

    class Context : public Content
    {
        public:
            Context();
            Context(const Context& context);
            ~Context();

            std::pair<Callback, int> function_get (const std::string& name) const;
            VarContent variable_get (const std::string& name) const;
            Module* module_get (const std::string&) const;

            void variable_set (const std::string&, MemoryObject<Content>*);
            void function_set (const std::string&, Callback, int);
            void module_set (const std::string&, Module*);

        private:
            std::map<std::string, std::pair<Callback, int>> functions_;
            std::map<std::string, VarContent> variables_;
            std::map<std::string, ModulePtr> modules_;
    };
}
#endif /* !CONTEXT_H_ */
