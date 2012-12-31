#ifndef STRING_HH
# define STRING_HH

# include <iostream>
# include <string>

# include "type.hh"

namespace esl
{
    class String : public Type
    {
        public:
            String (const std::string& data);
            ~String ();

            const std::string& data_get () const;
            void data_set (const std::string& data);

            virtual void print () const;
        private:
            std::string data_;
    };
}

#endif /* !STRING_HH */
