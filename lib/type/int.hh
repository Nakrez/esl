#ifndef INT_HH
# define INT_HH

# include <iostream>

# include "type.hh"

namespace esl
{
    class Int : public Type
    {
        public:
            Int ();
            ~Int ();

            virtual std::string type_name_get () const;

            virtual MemoryObject<Content>* print (const Params&);
            virtual MemoryObject<Content>* to_string (const Params&);

            virtual MemoryObject<Content>* plus_op (const Params&);
            virtual MemoryObject<Content>* minus_op (const Params&);
            virtual MemoryObject<Content>* mul_op (const Params&);
            virtual MemoryObject<Content>* div_op (const Params&);
            virtual MemoryObject<Content>* mod_op (const Params&);
            virtual MemoryObject<Content>* pow_op (const Params&);

            virtual MemoryObject<Content>* eq_op (const Params&);
            virtual MemoryObject<Content>* diff_op (const Params&);
            virtual MemoryObject<Content>* gt_op (const Params&);
            virtual MemoryObject<Content>* ge_op (const Params&);
            virtual MemoryObject<Content>* lt_op (const Params&);
            virtual MemoryObject<Content>* le_op (const Params&);

            virtual MemoryObject<Content>* and_op (const Params&);
            virtual MemoryObject<Content>* or_op (const Params&);
    };
}

#endif /* !INT_HH */
