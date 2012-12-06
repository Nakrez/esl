#ifndef FUNCTION_HH
# define FUNCTION_HH

# include "object.hh"
# include "callback.hh"
# include "params.hh"

namespace esl
{
    class Function
    {
        public:
            Function ();
            ~Function ();

            std::string get_name() const;
            Object* call(Params *);

        private:
            std::string name_;
            Callback *callback_;
    };
}
#endif /* !FUNCTION_HH */
