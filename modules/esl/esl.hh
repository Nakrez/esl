#ifndef ESL_HH
# define ESL_HH

# include <iostream>

# include "../../lib/extension.hh"
# include "../../lib/type/object.hh"

# include "../../src/execute/vm.hh"
# include "../../lib/gc/memory-object.hh"

class Esl: public esl::Extension
{
    public:
        void init ();

        esl::GCObject* function_exist(const esl::Params& params,
                                      esl::Context* context);
        esl::GCObject* module_exist(const esl::Params& params,
                                    esl::Context* context);
        esl::GCObject* variable_exist(const esl::Params& params,
                                      esl::Context* context);

        esl::GCObject* type_method(const esl::Params& params,
                                   esl::Context* context);
        esl::GCObject* type_attribut(const esl::Params& params,
                                     esl::Context* context);

        esl::GCObject* object_method(const esl::Params& params,
                                       esl::Context* context);
        esl::GCObject* object_attribut(const esl::Params& params,
                                       esl::Context* context);

        esl::GCObject* module_function(const esl::Params& params,
                                       esl::Context* context);
};

extern "C" Esl* get ();
extern "C" void destroy (Esl*);

#endif /* !ESL_HH */
