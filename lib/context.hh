#ifndef CONTEXT_H_
# define CONTEXT_H_

# include <string>
# include <map>

# include "object.hh"
# include "function.hh"

namespace esl
{
    class Context : public Object
    {
        public:
            Context();
            ~Context();

            Function* function_get (const std::string& name) const;

        private:
            std::map<std::string, Function*>* functions_;
    };
}
#endif /* !CONTEXT_H_ */
