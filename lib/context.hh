#ifndef CONTEXT_H_
# define CONTEXT_H_

# include <string>
# include <map>
# include <memory>

# include "module.hh"
# include "content.hh"
# include "exception.hh"

namespace esl
{
    class Params;
    class Runtime;

    using Callback = MemoryObject<Content>* (*)(Runtime*, const Params&);
    using MemContent = MemoryObject<Content>*;

    MemoryObject<Content>* std_callback (Runtime*, const Params&);

    class Context : public Content
    {
        public:
            Context();
            Context(const Context& context);
            ~Context();

            std::pair<Callback, int> function_get (const std::string& name) const;
            MemContent variable_get (const std::string& name) const;
            MemContent module_get (const std::string&) const;

            void variable_set (const std::string&, MemContent);
            void function_set (const std::string&, Callback, int);
            void module_set (const std::string&, MemContent);

        private:
            std::map<std::string, std::pair<Callback, int>> functions_;
            std::map<std::string, MemContent> variables_;
            std::map<std::string, MemContent> modules_;
    };
}
#endif /* !CONTEXT_H_ */
