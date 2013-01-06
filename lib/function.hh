/// @date 05/01/2012
#ifndef FUNCTION_HH
# define FUNCTION_HH

# include "params.hh"
# include "context.hh"
# include "content.hh"

namespace esl
{
    class Function : public Content
    {
        public:
            Function (int);
            Function (DelegateBase*);
            ~Function ();

            MemContent call (Context*, const Params&) const;

        private:
            int pc_;
            DelegateBase* callback_;
    };
}

#endif /* !FUNCTION_HH */
