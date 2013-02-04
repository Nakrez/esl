#ifndef IO_HH
# define IO_HH

# include <iostream>

# include "file.hh"

# include "../../lib/extension.hh"
# include "../../lib/type/object.hh"

# include "../../src/execute/vm.hh"

class Io: public esl::Extension
{
    public:
        void init ();

        esl::MemoryObject<esl::Content>* print (const esl::Params&,
                                                esl::Context*);
        esl::MemoryObject<esl::Content>* print_core (const esl::Params&);
        esl::MemoryObject<esl::Content>* print_newline (const esl::Params&,
                                                        esl::Context*);
        esl::MemoryObject<esl::Content>* read_line (const esl::Params&,
                                                    esl::Context*);
};

extern "C" Io* get ();
extern "C" void destroy (Io*);

#endif /* !IO_HH */
