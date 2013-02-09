#ifndef CONTEXT_H_
# define CONTEXT_H_

# include <string>
# include <map>
# include <memory>

# include "content.hh"
# include "exception.hh"
# include "gc/memory-object.hh"

namespace esl
{
    class Params;
    class Context;
    class Function;

    class Context : public Content
    {
        public:
            Context();
            Context(const Context& context);
            ~Context();

            bool function_exist(const std::string& name) const;
            bool module_exist(const std::string& name) const;
            bool variable_exist(const std::string& name) const;

            GCObject* function_get(const std::string& name) const;
            GCObject* variable_get(const std::string& name) const;
            GCObject* module_get(const std::string&) const;

            void variable_set(const std::string&, GCObject*);
            void function_set(const std::string&, GCObject*);
            void module_set(const std::string&, GCObject*);

            size_t pc_get() const;
            void pc_set(size_t);
            void pc_incr(int incr);

        private:
            std::map<std::string, GCObject*> functions_;
            std::map<std::string, GCObject*> variables_;
            std::map<std::string, GCObject*> modules_;

            size_t pc_;
    };
}

#endif /* !CONTEXT_H_ */
