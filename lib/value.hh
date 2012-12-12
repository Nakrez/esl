#ifndef ESL_VALUE_H_
# define ESL_VALUE_H_

# include <string>
# include <iostream>

# include "content-object.hh"

namespace esl
{
    class Value : public ContentObject
    {
        public:
            Value();
            Value(obj_type, void*);
            Value(const Value&);
            ~Value();

            void print();
    };
}
#endif /* !ESL_VALUE_H_ */
