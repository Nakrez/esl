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

        esl::GCObject* is_function_exist(const esl::Params& params,
                                         esl::Context* context);
        esl::GCObject* is_module_exist(const esl::Params& params,
                                       esl::Context* context);
        esl::GCObject* is_variable_exist(const esl::Params& params,
                                         esl::Context* context);
};

extern "C" Esl* get ();
extern "C" void destroy (Esl*);

#endif /* !ESL_HH */
