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

            virtual GCObject* size (const Params&);
            virtual GCObject* at (const Params&);
            virtual GCObject* split (const Params&);
            virtual GCObject* to_int (const Params&);

            virtual GCObject* construct (const Params&);

            virtual GCObject* print (const Params&);
            virtual GCObject* to_string (const Params&);

            virtual GCObject* plus_op (const Params&);

            virtual GCObject* eq_op (const Params&);
            virtual GCObject* diff_op (const Params&);
            virtual GCObject* gt_op (const Params&);
            virtual GCObject* ge_op (const Params&);
            virtual GCObject* lt_op (const Params&);
            virtual GCObject* le_op (const Params&);
    };
}

#endif /* !STRING_HH */
