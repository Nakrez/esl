#ifndef CONTEXT_H_
# define CONTEXT_H_

# include <string>
# include <map>

# include "object.hh"
# include "value.hh"

namespace esl
{
    class Params;
    class Runtime;
    class Module;

    using Callback = ContentObject* (*)(Runtime*, Params*);

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
            std::map<std::string, std::pair<Callback, int>>* functions_;
            std::map<std::string, Value*>* variables_;
            std::map<std::string, Module*>* modules_;
    };
}
#endif /* !CONTEXT_H_ */
