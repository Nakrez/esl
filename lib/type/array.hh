#ifndef ARRAY_HH
# define ARRAY_HH

# include <vector>

# include "../value.hh"
# include "../exception.hh"

namespace esl
{
    class Array
    {
        public:
            Array (unsigned int size);
            ~Array ();

            esl::Value* at (unsigned int);

        private:
            std::vector<esl::Value*> data_;
    };
}

#endif /* !ARRAY_HH */
