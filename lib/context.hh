#ifndef CONTEXT_H_
# define CONTEXT_H_

# include <string>
# include <map>

# include "object.hh"
# include "function.hh"
# include "value.hh"

namespace esl
{
    class Context : public Object
    {
        public:
            Context();
            Context(const Context& context);
            ~Context();

            Function* function_get (const std::string& name) const;
            Value* variable_get (const std::string& name) const;


            void variable_set (const std::string& name, Value* value);

        private:
            std::map<std::string, Function*>* functions_;
            std::map<std::string, Value*>* variables_;
    };
}
#endif /* !CONTEXT_H_ */
