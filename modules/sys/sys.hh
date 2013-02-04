#ifndef SYS_HH
# define SYS_HH

# include <iostream>

# include "../../lib/extension.hh"
# include "../../lib/type/object.hh"

# include "../../src/execute/vm.hh"

# include <unistd.h>

# include <sys/types.h>
# include <sys/wait.h>

class Sys : public esl::Extension
{
    public:
        void init ();

        esl::GCObject* fork_fun (const esl::Params&, esl::Context*);
        esl::GCObject* vfork_fun (const esl::Params&, esl::Context*);
        esl::GCObject* exit_fun (const esl::Params&, esl::Context*);
        esl::GCObject* chdir_fun (const esl::Params&, esl::Context*);
        esl::GCObject* getcwd_fun (const esl::Params&, esl::Context*);
        esl::GCObject* getenv_fun (const esl::Params&, esl::Context*);
        esl::GCObject* setenv_fun (const esl::Params&, esl::Context*);
        esl::GCObject* rename_fun (const esl::Params&, esl::Context*);
        esl::GCObject* remove_fun (const esl::Params&, esl::Context*);
        esl::GCObject* exec_fun (const esl::Params&, esl::Context*);
};

extern "C" Sys* get ();
extern "C" void destroy (Sys*);

#endif /* !SYS_HH */
