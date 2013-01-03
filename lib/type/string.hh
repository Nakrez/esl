#ifndef STRING_HH
# define STRING_HH

# include <iostream>
# include <string>

# include "type.hh"
# include "int.hh"

namespace esl
{
    class String : public Type
    {
        public:
            String (const std::string& data);
            ~String ();

            virtual MemoryObject<Content>* print (const Params&);
            virtual std::string type_name_get () const;

            virtual MemoryObject<Content>* plus_op (const Params&);

            const std::string& data_get () const;
            void data_set (const std::string& data);
        private:
            std::string data_;
    };
}

#endif /* !STRING_HH */
