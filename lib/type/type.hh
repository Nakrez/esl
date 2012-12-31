#ifndef TYPE_HH
# define TYPE_HH

# include "../content.hh"

namespace esl
{
    class Type : public Content
    {
        public:
            Type ();
            ~Type ();

            virtual void print () const = 0;
    };
}

#endif /* !TYPE_HH */
