#ifndef ESL_CALLBACK_HH
# define ESL_CALLBACK_HH

# include "context.hh"
# include "params.hh"
# include "object.hh"

namespace esl
{
    class Callback
    {
        public:
            Callback();
            ~Callback();

            virtual Object* call(Context *, Params *);
    };
}
#endif /* !ESL_CALLBACK */
