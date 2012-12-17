#ifndef CONTEXT_H_
# define CONTEXT_H_

# include <string>
# include <map>
# include <memory>

# include "object.hh"
# include "value.hh"
# include "module.hh"

namespace esl
{
    class Params;
    class Runtime;

    using Callback = ContentObject* (*)(Runtime*, Params*);
    using ModulePtr = std::shared_ptr<Module>;
    using ValuePtr = std::shared_ptr<Value>;

    ContentObject* std_callback (Runtime*, Params*);

    class Context : public Object
    {
        public:
            Context();
            Context(const Context& context);
            ~Context();

            std::pair<Callback, int> function_get (const std::string& name) const;
            Value* variable_get (const std::string& name) const;
            Module* module_get (const std::string&) const;

            void variable_set (const std::string&, Value*);
            void function_set (const std::string&, Callback, int);
            void module_set (const std::string&, Module*);

        private:
            std::map<std::string, std::pair<Callback, int>> functions_;
            std::map<std::string, ValuePtr> variables_;
            std::map<std::string, ModulePtr> modules_;
    };
}
#endif /* !CONTEXT_H_ */
