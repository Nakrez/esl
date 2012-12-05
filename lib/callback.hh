#ifndef ESL_CALLBACK_HH
# define ESL_CALLBACK_HH

namespace esl
{
    class EslCallback
    {
        public:
            EslCallback();
            ~EslCallback();

            virtual EslOBject *call(EslContext *, EslParams *);
    };
}
#endif /* !ESL_CALLBACK */
