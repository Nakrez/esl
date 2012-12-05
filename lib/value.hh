#ifndef ESL_VALUE_H_
# define ESL_VALUE_H_

# include <string>
# include <iostream>

# include "object.hh"

namespace esl
{
    class Value : public Object
    {
        public:
            Value();
            Value(obj_type, void*);
            ~Value();

            void print();
    };
}
#endif /* !ESL_VALUE_H_ */
