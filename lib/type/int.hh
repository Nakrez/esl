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

            virtual GCObject* construct (const Params&);

            virtual GCObject* print (const Params&);
            virtual GCObject* to_string (const Params&);

            virtual GCObject* plus_op (const Params&);
            virtual GCObject* minus_op (const Params&);
            virtual GCObject* mul_op (const Params&);
            virtual GCObject* div_op (const Params&);
            virtual GCObject* mod_op (const Params&);
            virtual GCObject* pow_op (const Params&);

            virtual GCObject* eq_op (const Params&);
            virtual GCObject* diff_op (const Params&);
            virtual GCObject* gt_op (const Params&);
            virtual GCObject* ge_op (const Params&);
            virtual GCObject* lt_op (const Params&);
            virtual GCObject* le_op (const Params&);

            virtual GCObject* and_op (const Params&);
            virtual GCObject* or_op (const Params&);
    };
}

#endif /* !INT_HH */
