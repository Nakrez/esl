#ifndef CALLBACK_HH
# define CALLBACK_HH

# include "context.hh"
# include "params.hh"
# include "object.hh"

class Context;

namespace esl
{
    class Callback : public Object
    {
        public:
            Callback();
            ~Callback();

            virtual Object* call(Context *, Params *);
    };
}
#endif /* !CALLBACK_HH */
