#ifndef ESL_PARAMS_HH
# define ESL_PARAMS_HH

# include <deque>

# include "object.hh"
# include "value.hh"

namespace esl
{
    class Params : public Object
    {
        public:
            Params ();
            ~Params ();

            bool empty () const;
            int count () const;
            Value* get_params (int) const;
            void params_set (Value*);

        private:
            std::deque<Value*> params_;
    };
}

#endif /* !ESL_PARAMS_HH */
