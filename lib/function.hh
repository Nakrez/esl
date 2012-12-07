#ifndef FUNCTION_HH
# define FUNCTION_HH

# include <string>

# include "object.hh"
# include "params.hh"

namespace esl
{
    class Runtime;
    class ContentObject;

    using Callback = esl::ContentObject* (*)(esl::Runtime*, esl::Params*);

    class Function
    {
        public:
            Function ();
            ~Function ();

            std::string get_name() const;
            ContentObject* call(Runtime*, Params *);

        private:
            std::string name_;
            Callback callback_;
    };
}
#endif /* !FUNCTION_HH */
