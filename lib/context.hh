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
    class Context;
    class Function;

    using MemContent = MemoryObject<Content>*;
    using Callback = MemContent (*)(Context*, const Params&);

    class Context : public Content
    {
        public:
            Context();
            Context(const Context& context);
            ~Context();

            MemContent function_get (const std::string& name) const;
            MemContent variable_get (const std::string& name) const;
            MemContent module_get (const std::string&) const;

            void variable_set (const std::string&, MemContent);
            void function_set (const std::string&, MemContent);
            void module_set (const std::string&, MemContent);

            size_t pc_get () const;
            void pc_set (size_t);
            void pc_incr (int incr);

        private:
            std::map<std::string, MemContent> functions_;
            std::map<std::string, MemContent> variables_;
            std::map<std::string, MemContent> modules_;

            size_t pc_;
    };
}

#endif /* !CONTEXT_H_ */
