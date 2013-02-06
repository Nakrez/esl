#ifndef STRING_HH
# define STRING_HH

# include <iostream>
# include <string>
# include <sstream>

# include "type.hh"

namespace esl
{
    class String : public Type
    {
        public:
            String ();
            ~String ();

            virtual std::string type_name_get () const;

            virtual void init ();

            virtual GCObject* size (const Params&, Context*);
            virtual GCObject* at (const Params&, Context*);
            virtual GCObject* split (const Params&, Context*);
            virtual GCObject* to_int (const Params&, Context*);
            virtual GCObject* empty (const Params&, Context*);
            virtual GCObject* insert (const Params&, Context*);

            virtual GCObject* construct (const Params&, Context*);

            virtual GCObject* print (const Params&, Context*);
            virtual GCObject* to_string (const Params&, Context*);

            virtual GCObject* plus_op (const Params&, Context*);

            virtual GCObject* eq_op (const Params&, Context*);
            virtual GCObject* diff_op (const Params&, Context*);
            virtual GCObject* gt_op (const Params&, Context*);
            virtual GCObject* ge_op (const Params&, Context*);
            virtual GCObject* lt_op (const Params&, Context*);
            virtual GCObject* le_op (const Params&, Context*);
    };
}

#endif /* !STRING_HH */
