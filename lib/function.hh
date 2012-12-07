#ifndef FUNCTION_HH
# define FUNCTION_HH

# include <string>

# include "object.hh"
# include "params.hh"

namespace esl
{
    class Runtime;
    class ContentObject;


    class Function
    {
        public:
            Function (std::string, Callback);
            ~Function ();

            std::string get_name() const;
            ContentObject* call(Runtime*, Params *);

        private:
            std::string name_;
            Callback callback_;
    };
}
#endif /* !FUNCTION_HH */
