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

            virtual GCObject* construct (const Params&, Context*);

            virtual GCObject* print (const Params&, Context*);
            virtual GCObject* to_string (const Params&, Context*);

            virtual GCObject* plus_op (const Params&, Context*);
            virtual GCObject* minus_op (const Params&, Context*);
            virtual GCObject* mul_op (const Params&, Context*);
            virtual GCObject* div_op (const Params&, Context*);
            virtual GCObject* mod_op (const Params&, Context*);
            virtual GCObject* pow_op (const Params&, Context*);

            virtual GCObject* eq_op (const Params&, Context*);
            virtual GCObject* diff_op (const Params&, Context*);
            virtual GCObject* gt_op (const Params&, Context*);
            virtual GCObject* ge_op (const Params&, Context*);
            virtual GCObject* lt_op (const Params&, Context*);
            virtual GCObject* le_op (const Params&, Context*);

            virtual GCObject* and_op (const Params&, Context*);
            virtual GCObject* or_op (const Params&, Context*);
    };
}

#endif /* !INT_HH */
