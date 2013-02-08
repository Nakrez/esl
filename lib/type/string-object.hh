#ifndef STRING_OBJECT_HH
# define STRING_OBJECT_HH

# include <string>

# include "object.hh"

namespace esl
{
    class StringObject : public Object
    {
        public:
            StringObject();
            StringObject(const std::string& data);

            const std::string& data_get() const;
            void data_set(const std::string& data);

            void erase(int start, int len);

        private:
            std::string data_;
    };
}

#endif /* !STRING_OBJECT_HH */
